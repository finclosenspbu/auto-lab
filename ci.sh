#!/bin/sh
# ci.sh — те же шаги, что в .github/workflows/ci.yml, но локально.
# Нужен, чтобы проверять сборку до push и работать без GitHub.
#
#   ./ci.sh          # обычная сборка
#   ./ci.sh clang    # другой компилятор (как matrix в Actions)
set -eu

CC_ARG=${1:-gcc}
ROOT=$(cd "$(dirname "$0")" && pwd)
cd "$ROOT"

echo "=== компилятор: $CC_ARG ==="
"$CC_ARG" --version | head -n 1

echo "=== чистая сборка ==="
make clean
make CC="$CC_ARG"

echo "=== тесты ==="
make test CC="$CC_ARG"

echo "=== пакет ==="
./packaging/build-deb.sh

echo "=== готово ==="
ls -1 dist/*.deb
