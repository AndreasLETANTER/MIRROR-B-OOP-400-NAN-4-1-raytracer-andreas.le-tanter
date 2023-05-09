# RayTracer

The goal of this project is to create a scene in 3D with a camera, lights (ambient, point, directional..), spheres, cylinder and plane. Then, we need to render the scene in a .ppm file.

## Installation

To install this project, you need to follow this steps:

```bash
git clone git@github.com:AndreasLETANTER/MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter.git
cd MIRROR-B-OOP-400-NAN-4-1-raytracer-andreas.le-tanter
cmake .
make
```

## Usage

To use this project, you need to follow this steps:

```bash
./raytracer [configuration file] > [output file]
```

- **configuration file** : the path of the configuration file, the file must be follow the configuration file documentation

- **output file** : the path of the output file, the file must be a .ppm file

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

You can find configuration file Documentation here -> [Configuration](CONFIGURATION-FILE.md)

Also all our code was compatible with Doxygen