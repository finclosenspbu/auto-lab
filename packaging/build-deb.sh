#!/bin/sh
# build-deb.sh — собрать .deb из уже собранного проекта.
#
#   ./ci.sh && ./packaging/build-deb.sh
#   dpkg-deb -c dist/hello_1.0.0_amd64.deb    # посмотреть содержимое
#
# DESTDIR — «будущая система»: файлы раскладываются по пути установки,
# но пакет собирается без root.
set -eu

VERSION=1.1.0
ARCH=amd64
NAME=hello
ROOT=$(cd "$(dirname "$0")/.." && pwd)
STAGE=build/deb          # относительный путь: пробелы в пути проекта ломают make

cd "$ROOT"

make >/dev/null
rm -rf "$STAGE"
make install DESTDIR="$STAGE" PREFIX=/usr >/dev/null

mkdir -p "$STAGE/DEBIAN"
cp "$ROOT/packaging/DEBIAN/control" "$STAGE/DEBIAN/control"
sed -i "s/^Version:.*/Version: $VERSION/" "$STAGE/DEBIAN/control"
sed -i "s/^Architecture:.*/Architecture: $ARCH/" "$STAGE/DEBIAN/control"

mkdir -p dist
echo "собираю пакет…"
dpkg-deb --root-owner-group --build "$STAGE" "dist/${NAME}_${VERSION}_${ARCH}.deb"
