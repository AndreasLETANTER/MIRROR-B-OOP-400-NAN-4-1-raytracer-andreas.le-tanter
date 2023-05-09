# Configuration file

The goal of a configuration file defines the properties of a 3D scene, including the camera, lights, spheres, cylinder in the scene. The configuration is written in a custom format that described below.

## Global Configuration

For the sake of unification all values must be in **sizeof(double)** format.
You can put a comment in the configuration file by using the **#** character.

## Create a camera

The camera is defined as a dictionary that contains three properties:

```JSON
camera = {
    resolution = {
        width = 1000.0,
        height = 1000.0
    },
    screen = {
        origin = {
            x = -0.5, y = -0.5, z = -4.0
        },
        max_x = {
            x = 1.0, y = 0.0, z = 0.0
        },
        max_y = {
            x = 0.0, y = 1.0, z = 0.0
        }
    },
    fov = 25.0
}
```

1 - **camera** : the name of the camera in the scene, it must be unique and he need to have "camera" prefix

2 - **resolution** : the resolution of the camera, it must be present to be valid. The resolution property is a vector of two values (width, height) that define the resolution of the camera.

3 - **screen** : the screen of the camera, it must be present to be valid. The screen property is a dictionary that contains three properties (origin, max_x, max_y). The origin property is a vector of three values (x, y, z) that define the origin of the screen. The max_x property is a vector of three values (x, y, z) that define the max_x of the screen. The max_y property is a vector of three values (x, y, z) that define the max_y of the screen.

# Object types

## Create a sphere

The sphere is defined as a dictionary that contains four properties:

```JSON
sphere-Brown = {
    position = {
        x = 0.5, y = 0.5, z = 0.0
    },
    radius = 0.3,
    color = {
        r = 153.0, g = 0.0, b = 153.0
    }
}
```

1 - **shere-Brown** : the name of the sphere in the scene, it must be unique and he need to have "sphere-" prefix

2 - **position/radius/color** : the properties of the sphere he must be present to be valid. The position property is a vector of three values (x, y, z) that define the position of the sphere in the scene. The radius property is a double that define the radius of the sphere. The color property is a vector of three values (r, g, b) that define the color of the sphere.

## Create a plane

The plane is defined as a dictionary that contains four properties:

```JSON
plane-Luchooooo = {
    position = {
        x = 2.5, y = 2.5, z = 3.0
    },
    normal = {
        x = 5.0, y = 5.0, z = 3.0
    },
    color = {
        r = 255.0, g = 10.0, b = 35.0
    }
}
```

1 - **plane-Luchooooo** : the name of the plane in the scene, it must be unique and he need to have "plane-" prefix

2 - **position/normal/color** : the properties of the plane he must be present to be valid. The position property is a vector of three values (x, y, z) that define the position of the plane in the scene. The normal property is a vector of three values (x, y, z) that define the normal of the plane. The color property is a vector of three values (r, g, b) that define the color of the plane.

# Lights types

## Create a point light

The point light is defined as a dictionary that contains three properties:

```JSON
point-Sun = {
    position = {
        x = -10.0, y = 2.0, z = 2.0
    },
    intensity = 0.6
}
```

1 - **point-Sun** : the name of the point light in the scene, it must be unique and he need to have "point-" prefix

2 - **position/intensity** : the properties of the point light he must be present to be valid. The position property is a vector of three values (x, y, z) that define the position of the point light in the scene. The intensity property is a double that define the intensity of the point light.

## Create a directional light

The directional light is defined as a dictionary that contains three properties:

```JSON
directional-pipe = {
    direction = {
        x = -1.0, y = 1.0, z = 1.5
    }
}
```

1 - **directional-pipe** : the name of the directional light in the scene, it must be unique and he need to have "directional-" prefix

2 - **direction** : the properties of the directional light he must be present to be valid. The direction property is a vector of three values (x, y, z) that define the direction of the directional light in the scene.

## Create an ambient light

The ambient light is defined as a dictionary that contains one property:

```JSON
ambient-moon = {
    intensity = 0.2
}
```

1 - **ambient-moon** : the name of the ambient light in the scene, it must be unique and he need to have "ambient-" prefix

2 - **intensity** : the properties of the ambient light he must be present to be valid. The intensity property is a double that define the intensity of the ambient light.

## Exemples of configurations files