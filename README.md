# RayTracer

The goal of this project is to create a 3D scene with a camera, lights (ambient, point, directional..), spheres, cylinders and planes. Then, we need to render the scene in a .ppm file.

## Installation

To install this project, you need to follow these steps:

```bash
git clone git@github.com:AndreasLETANTER/MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter.git
cd MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
cmake .
make
```

## Usage

To use this project, you need to follow these steps:

```bash
./raytracer [configuration file]
```

- **configuration file** : the path of the configuration file, the file must follow the configuration file documentation

By default, the program will render the scene in output.ppm in scenes folder

If you want graphics, you can run the program without any argument

```bash
./raytracer
```

## Example

```bash
./raytracer ./scenes/test.cfg > ./scenes/test.ppm
```

## Authors

- [@HugoN1](https://www.github.com/HugoN1)
- [@Luchooooo](https://www.github.com/lbarreteau)
- [@Andréas LE TANTER](https://www.github.com/AndreasLETANTER)
- [@Ycuzou22](https://www.github.com/ycuzou22)

## Documentation

You can find the configuration file Documentation here -> [Configuration](CONFIGURATION-FILE.md)

Also all our code is compatible with Doxygen
