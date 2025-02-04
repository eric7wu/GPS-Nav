# GPS Waypoint Navigation

This repository hosts functions that can calculate distance, bearing, directions and more using latitude and longitude.

Running main.cpp will cause a UI to appear. Initially there will be a prompt to type in the number of coordinates you want to enter. You will then input that amount of coordinates. This will then generate a vector with directions in the form of magnitude and angle.

```
Type in the number of coordinates you want to enter?

Please type in your coordinates:
...

Mapping created.
```

You will then have these functions available.

## Add

`add latitude longitude position`\
This adds a point at a certain position (1-indexed).

Ex. `add 1.000 2.000 1 `, which adds the coordinate (1, 2) at position 1 of the vector

## Remove

`rm position`\
This removes a point at a certain position (1-indexed).

Ex. `rm 2 `, which removes the coordinate at position 2 of the vector

## Return

`ret position`\
This returns the point at the specified position (1-indexed).

Ex. `ret 2 `, which returns the coordinate at position 2 of the vector

## See

`sc `\
`sd `\
This prints out the coordinates vector and the directions vector respectively.

## Quit

`q` \
This quits the UI.
