# lab_intro

This is the first lab homework, the main focus is doing some filter on image <br>

### Understanding the HSL Color Space

* Hue (denoted as h) defines the color itself, for example, red in distinction to blue or yellow. The values for the hue axis run from 0–360° beginning and ending with red and running through green, blue and all intermediary colors like greenish-blue, orange,purple, etc.<br>
* Saturation (denoted as s) indicates the degree to which the hue differs from a neutral gray. The values run from 0%, which is no color saturation, to 100%, which is the fullest saturation of a given hue at a given percentage of illumination.<br>
* Luminance (denoted as l) indicates the level of illumination. The values run as percentages; 0% appears black (no light) while 100% is full illumination, which washes out the color (it appears white).<br><br>

### Doing several image filters<br><br>
<img src="https://github.com/cocolin041/Data_structure/blob/master/HW/lab_intro/alma.png" width="300"> Original Image<br><br>

* Graystyle <br>
Tuning every pixel's saturate into 0% <br><br>
<img src="https://github.com/cocolin041/Data_structure/blob/master/HW/lab_intro/out-grayscale.png" width="300"><br><br>

* Special transform on hue <br>
transform the hue of every pixel to Illini Orange (h=11) or Illini Blue (h = 216).<br><br>
<img src="https://github.com/cocolin041/Data_structure/blob/master/HW/lab_intro/out-illinify.png" width="300"><br><br>

* Spotlight <br>
Create a spotlight centered at a given point: (centerX, centerY) <br><br>
<img src="https://github.com/cocolin041/Data_structure/blob/master/HW/lab_intro/out-spotlight.png" width="300"><br><br>

* Watermark <br>
Watermark an image onto another <br><br>
<img src="https://github.com/cocolin041/Data_structure/blob/master/HW/lab_intro/overlay.png" width="300"> Watermark image<br><br>
<img src="https://github.com/cocolin041/Data_structure/blob/master/HW/lab_intro/out-watermark.png" width="300"><br><br>
