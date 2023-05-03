# Configuration file

The goal of a configuration file defines the properties of a 3D scene, including the camera, lights, spheres, cylinder in the scene. The configuration is written in a custom format that described below.

## Global Configuration

For the sake of unification all values must be in **sizeof(double)** format.

## Configuration of the camera

The camera is defined as a dictionary that contains four properties:

```JSON
sphere-Brown = {
    position = {
        x = 0.5, y = 0.5, z = 0.0
    }
    radius = 0.3
    color = {
        r = 153.0, g = 0.0, b = 153.0
    }
}
```

1 - **shere-Brown** : the name of the sphere in the scene, it must be unique and he need to have "sphere-" prefix

2 - **position/radius/color** : the properties of the sphere he must be present to be valid. The position property is a vector of three values (x, y, z) that define the position of the sphere in the scene. The radius property is a double that define the radius of the sphere. The color property is a vector of three values (r, g, b) that define the color of the sphere.

## Exemples of configurations files
