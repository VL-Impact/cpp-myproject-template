# cpp-template
This project features some standard layout for quick-starting a CPP project.

## Building
This template uses self-contained CMakeLists file with Conan-managed dependencies.

Pre-requisites:
 - CMake 3.10 or higher
 - Conan 1.55.0 or higher is installed and in the path (on my machine I may need to run `eval "$(pyenv init -)"` first)

If you have it, go run:

```bash
eval "$(pyenv init -)"
mkdir _build
cd _build
cmake .. -DCMAKE_BUILD_TYPE=Release
cmake --build . 
```

See the `_build/bin` folder for binaries.

## ToDo
In future I may transform this template into cookiecutter.