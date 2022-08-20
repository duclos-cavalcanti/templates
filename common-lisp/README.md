# Common Lisp Template/Tutorial
Minimal template project for common lisp applications. Uses the [asdf](https://common-lisp-libraries.readthedocs.io/asdf/) build tool to manage the project, it's dependencies and
testing. The testing library used here is [prove](https://github.com/fukamachi/prove).

Also, there are example source files in `example` and docs that were used as a learning material for common lisp.

## Dependencies
- [quicklisp](https://www.quicklisp.org/beta/)
- [sbcl](http://www.sbcl.org/)

1. Installation
```sh
sudo pacman -S sbcl quicklisp
sbcl --load '/usr/share/quicklisp/quicklisp.lisp' --eval '(quicklisp-quickstart:install)' --quit
```

2. Quicklisp Configuration
```lisp
$ sbcl    # enter REPL
(load "~/quicklisp/setup.lisp")
(ql:add-to-init-file)
```

3. ASDF Configuration
Needed to asdf files can be found. Look [here](https://asdf.common-lisp.dev/asdf.html#Configuring-ASDF-to-find-your-systems)
```sh
mkdir -p ~/.config/common-lisp/source-registry.conf.d/
cd ~/.config/common-lisp/source-registry.conf.d/
touch dev.conf
echo '(tree "path to your cl projects")' >> dev.conf
```

## Targets

1. `make`: compiles and runs application
2. `make test`: runs tests
4. `make clean`: cleans binary

## Acknowledgments

* [anilsathyan7/lisp](https://github.com/anilsathyan7/lisp)
* [boechat107/cl-project-template](https://github.com/boechat107/cl-project-template)
* "Common Lisp In a Nutshell,19th September,2003"

