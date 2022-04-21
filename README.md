# ROUGE C

![RougeC](http://nikolapacekvetnic.rs/wp-content/uploads/2022/04/Screenshot-2022-04-21-at-01.40.31.png)

Recreation of classic Rouge game in C. C practice project.

## Tips

### Printing UTF-8 in C

You need to initialize the locale's encoding by calling `setlocale` at your program's start, like so:

```
    setlocale(LC_CTYPE, "")
```

This is normally carried out for you if you use some initialization function.

## Links

![Generate Random Cave Levels Using Cellular Automata](https://gamedevelopment.tutsplus.com/tutorials/generate-random-cave-levels-using-cellular-automata--gamedev-9664)
