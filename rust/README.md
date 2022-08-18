# rust-project-template

[![Crates.io](https://img.shields.io/crates/v/{{project-name}}.svg)](https://crates.io/crates/{{project-name}})
[![Docs.rs](https://docs.rs/project-template/badge.svg)](https://docs.rs/{{project-name}})
[![license](http://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/duclos-cavalcanti/rust-project-template/LICENSE)

## Installation

### Arch Linux Installation
1. Run `sudo pacman -S rustup`
2. Run `rustup update stable` to install rust.
2. Run `rustup component add rls rust-analysis rust-src` to have optional development
   software for rust.

### Generic Installation

* Install the rust toolchain in order to have cargo installed by following [this](https://www.rust-lang.org/tools/install) guide.
* Run `cargo install <project-name>` to install this or any rust project.

## Development
1. `cargo build`: builds project and creates target folder with outputted files and executable.
2. `cargo build --release`: stores executable in `target/release` and performs some optimizations to the binary.
3. `cargo run`: builds project and runs executable.
4. `cargo check`: checks if project compiles without building it.
5. `cargo fmt`: formats all rust files according to `rustfmt.toml`
6. `cargo test`: runs unit-tests.

## License

Licensed under:
 * MIT license
   ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)

