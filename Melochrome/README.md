# MELOCHROME
#### **Video Demo:**  https://youtu.be/05T5n1Zc7Mg
#### **Description:** Melochrome is a web application that takes an audio file (mp3) as input and plays a colorful visualization along with it based on its frequency distribution and loudness. It was developed using HTML structure, CSS styling and Javascript code.

## Features

- Supports MP3 audio files
- Responsive canvas for visualizing audio frequency and loudness
- Fullscreen mode
- Smooth and neutral background colors

## Files included

- `index.html` contains the project as a whole.
- `test.html` was used whenever making major changes, which in the process ended up introducing undesired bugs. `test.html` made sure that `index.html` would always contain a version that worked appropriately.
- `README.md` describes the project and its parts.

## HTML Structure

- `<meta>` and `</meta>`: Here's where the character encoding and viewport settings are being defined.
- `<title>` and `</title>`: Here is the title of the project, which will be displayed on top (Melochrome).

In the `<body>` section, there are a few tags for key elements of the web page:

- `<label>` for the text "Choose Audio File".
- `<input>`, which creates a file input field
- `<button>`, which creates a "Full Screen" button.
- The `<canvas>` tag creates the area where the visualization will be shown.
- And the `<audio>` tag creates the audio player with its basic controls.

## CSS Styling

Between `<style>` and `</style>` inside the `<head>` section.

- `body`, `html`: sets margin, padding, and the background gradient. I went for these colors which I found pretty smooth and neutral.
- `#audioFile`: actually hides the file input field.
- `#audioPlayer`: styles the audio player's position, background color, width, and so on.
- `canvas`: sets the display and margin for the canvas element.
- `#fullScreen`: styles the fullscreen button's position, background color, etc.
- `label`: styles the label for the file input field.

## JavaScript Code

Between the `<script>` and `</script>` tags in the `<body>` section.

- I have some DOM elements and variables being cached for later use.

Functions:

- `setCanvasResolution`: Adjust the canvas resolution based on the device's pixel ratio.
- `resetVisualizer`: Resets the visualizer by clearing the canvas and canceling existing frames.
- `draw`: (...)

## The Draw Function

The `draw` function is responsible for creating the visualization of the audio frequencies on the canvas. It performs the following tasks:

1. **Request Animation Frame**: The function calls `requestAnimationFrame` to optimize the animation performance and ensure smooth rendering. It tells the browser to call the `draw` function again before the next repaint, creating a loop.

2. **Get Frequency Data**: The function retrieves frequency data from the `analyser` object, which is an instance of `AnalyserNode`. This object is part of the Web Audio API and provides real-time frequency data of the audio being played.

3. **Clear Canvas**: Before drawing the new frame, the function clears the entire canvas to ensure that the previous frame's visualization doesn't overlap with the new one.

4. **Draw Bars**: Based on the frequency data, the function draws vertical bars on the canvas, where each bar represents a specific frequency range. The height and color of the bars are determined by the amplitude (loudness) of the frequency.

Here's the breakdown of the `draw` function in the JavaScript code:

```javascript
function draw() {
  // 1. Request Animation Frame
  requestAnimationFrame(draw);

  // 2. Get Frequency Data
  analyser.getByteFrequencyData(frequencyData);

  // 3. Clear Canvas
  ctx.clearRect(0, 0, canvas.width, canvas.height);

  // 4. Draw Bars
  for (let i = 0; i < numBars; i++) {
    const value = frequencyData[i];
    const percent = value / 255;
    const height = canvas.height * percent;
    const offset = canvas.height - height - 1;
    const barWidth = canvas.width / numBars;
    const hue = i / numBars * 360;

    ctx.fillStyle = 'hsl(' + hue + ', 100%, 50%)';
    ctx.fillRect(i * barWidth, offset, barWidth, height);
  }
}
```

EventListeners:

- `fileInput`'change': Resets the visualizer for a new audio file if the user is done with the first one.
- `audioPlayer`'loadeddata': Sets up the visualizer and starts the animation.
- `fulScreenBtn`'click': Toggles the fullscreen mode.
- `window` 'resize': Adjusts the canvas size and resolution when the window is resized.
