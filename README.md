# Simple Pendulum Analysis in C++

A project for the Physics 2 course, originally implemented in Python and now re-implemented in C++ using the OpenCV library. The goal is to analyze the damped harmonic motion of a simple pendulum.

## Core Functionalities
* **Video Processing:** The C++ program uses OpenCV to read a video file of an oscillating pendulum (M ≈ 100g, L ≈ 0.5m).
* **Object Tracking:** It processes the video frame-by-frame, applying color filters to isolate and identify the position of the pendulum bob against a contrasting background.
* **Data Extraction:** The application tracks the horizontal (x) position of the bob and its corresponding timestamp for each frame.
* **Data Output:** The collected data (timestamp and x-position) is saved to a `.txt` file.

## Analysis
The output data is then used in analysis software (like gnuplot, scidavis, or origin) to fit the damped harmonic oscillator equation:
$$x(t) = A e^{-\gamma t} \cos(\omega t + \phi)$$
From the fitted parameters, the quality factor (Q-factor) of the system is determined.

## Technologies Used
* **Language:** C++
* **Library:** OpenCV
