# Using Eink Display

- Download Arduino IDE

- Make sure you install OS relevant board USB driver for arduino so that use connection can be detected in `Menubar->Tools->Port`

- Use `Menubar->Tools->Manage Libraries` and search and install [GxEPD2](https://github.com/ZinggJM/GxEPD2) and its dependencies

# Wiring Connection

- Busy -> D7
- RST -> D8
- DC -> D9
- CS -> D10
- CLK -> D13
- DIN -> D11
- GND -> Any Ground
- VCC -> 3.3 V


# Using Code

- Connect Arduino to computer and use above wiring connection with E-Ink waveshare 4.2 inch Black White 4 Gray. Push the code to arduino to see the display change

- Use following website to convert image to cpp [image2cpp](https://javl.github.io/image2cpp/`) (Make sure to select arduino code in section 4)

- example image can be found at `GxEPD2_PuruBee/puru_bee.h`

- For 4.2 Inch Waveshare Eink, You need to uncomment following line in `GxEPD2_display_selection.h` as shown in `GxEPD2_Example` directory.
```
GxEPD2_BW<GxEPD2_420, MAX_HEIGHT(GxEPD2_420)> display(GxEPD2_420(/*CS=10*/ SS, /*DC=*/ 9, /*RST=*/ 8, /*BUSY=*/ 7)); // GDEW042T2
```

# Tips

- Or you can manually define the display variable as following (to decrease global memory usage)
```cpp
//Global
GxEPD2_BW<GxEPD2_420, MAX_HEIGHT(GxEPD2_420)> *display; // Global

// Inside void Setup()
display = new GxEPD2_BW<GxEPD2_420, MAX_HEIGHT(GxEPD2_420)>(GxEPD2_420(/*CS=10*/ SS, /*DC=*/ 9, /*RST=*/ 8, /*BUSY=*/ 7));
```

- Remove any printf statement or use PROGMEM to decrease the RAM usage