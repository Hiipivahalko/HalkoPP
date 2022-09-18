# HalkoPP

Repository to for my own cpp-libraries. Some functions could be find in other libraries. Purpose test implementing things by own.

## Documentation

Run following command to get mkdocs server to read documentation or read from [here](./docs)

```bash
mkdocs serve
```

Then go to url `http://localhost:8000`

## Prerequirements

```bash
mkdir -p external/cpp_libs
```
* Install [SDSL](https://github.com/simongog/sdsl-lite)-libary (see install instructions from link) to
`<repo-root>/external/cpp_libs` or modify `Makefile` SDSL config paths.

### Optional config

For VIM run following command after external lib installation for coc.vim to find sources:

```bash
bear -- make
```
This command creates file `compile_commands.json`.

## Compile program

Run following command in root of the project to compile source files:

```bash
make
```

To run the program execute on terminal

```bash
./build/halkoPP
```

## TEST libraries

Run scriptfile `run_all_tests.sh` in project root directory:

```bash
./run_all_tests.sh
```
