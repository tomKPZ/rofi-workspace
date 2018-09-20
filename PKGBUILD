pkgname=rofi-qalc
pkgver=0.0.1
pkgrel=1
pkgdesc="Plugin to use rofi as a calculator"
url="https://github.com/tomKPZ/rofi-qalc"
arch=("x86_64")
license=("GPL3")
depends=("rofi")
makedepends=("git")

source=("${pkgname}::git+git://github.com/tomKPZ/rofi-qalc.git")
md5sums=("SKIP")

build() {
    cd "$srcdir/${pkgname}"
    autoreconf -i
    ./configure
    make
}

package() {
    cd "$srcdir/${pkgname}"
    make DESTDIR="$pkgdir" PREFIX=/usr install
}
