# Audio engine development

---

> [!NOTE]
> This is currently and ongoing project

---

## Background
A bucket list and honours project developed and engineered by Jan Huss

For a few years, I have been toying with the thought of building an audio engine. It sounds like an ambitious and daunting tasks just by saying it out loud. But people need to continue understanding an audio engine's architecture and structure so that we can continue making awesome tools for the sound creators!

After winning Dare Academy 2023, 3 friends and I decided to form a company to continue the development of our award winning game **"Book of Abominations"**. And I thought to myself..."What if I could build an audio engine and replace it with the FMOD Studio engine we currently have in place?...."

## Project goals
An amazing opportunity arose in which I could build this project for two modules while keeping two goals in mind: 
1. Build an audio engine for my honours degree. The research question is: "How would you design and build an audio engine while keeping the audio budget to a minimum?"
2. In audio programming, I will focus on developing a structure for implementing effects within my engine.

## Current progress:
- ~~initial stages. Honours project idea submitted~~
- ~~removed initial code and setup a project using **GLFW** and **Dear ImGui**~~
- Added PortAudio and MiniAudio libraries to the project. Played around with the engine layout and can play back basic sine and saw waveforms
<br>
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/)

## Libraries used
- [PortAudio](https://www.portaudio.com/): Audio Playback
- [MiniAudio](https://miniaud.io/): Audio asset handling
- [Dear ImGui](https://github.com/ocornut/imgui): For UI interaction
- [GLFW](https://www.glfw.org/): Framework for UI
