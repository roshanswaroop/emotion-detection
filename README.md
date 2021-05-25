# For ENGR 40M Grading:
All of the direct implementation is going to be in `ard.py`, `emotion_webcam_demo.py`, and `display.ino`, in `../src`but feel free to browse other aspects I used from Travis. I kept his Git history for sake of full transparency and to fully uphold the spirit of the Stanford Honor Code. (and to also give Travis props for an awesome job!) 

# Face Classification 
The following repository is a real-time face detection and emotion classification model.
Credit goes to Travis Tang for the original design and guide for implementation.
<p align="center">
    <img width="320" height="350" src="https://github.com/roshanswaroop/emotion-detection/blob/master/images/IMG_2719.png">
    <img width="467" height="350" src="https://raw.githubusercontent.com/travistangvh/emotion-detection-in-real-time/master/images/demo1.gif">
</p>


The face detection is powered by MTCNN and openCV. The emotion classification model is a built on an CNN architecture called VGGFace with weights trained on the fer2013 dataset.

## The Model
The model is trained on a CNN architecture called VGGFace, I replicated some of Travis's implementation for practice, but major credit goes to him for doing the heavy lifting on creating the model.


<p align="center">
    <img src="https://raw.githubusercontent.com/travistangvh/emotion-detection-in-real-time/master/images/VGGFaceNetwork.jpg">
</p>


## Instructions on getting started
### To run the demo.
* Clone this commit to your local machine using `git clone `

* Install these dependencies with pip install
`pip install -r ../REQUIREMENTS.txt` It may not work at first, so Google alternate versions of dependencies if pip is giving trouble. You can open the .txt file to see what ballpark of versions should be used.

* Download pretrained model and weight `trained_vggface.h5` from [here](https://drive.google.com/file/d/1Wv_Z4lAa7BgYqSAeceK9TxJNfwoLTwKy/view?usp=sharing).

* Place `trained_vggface.h5` into `../datasets/trained_models/`.
* Upload `display.ino` to your Arduino Uno. You will need access to Stanford ENGR40M's Lab 2A handout to build the hardware.

* Run `emotion_webcam_demo.py` using `python3 emotion_webcam_demo.py`

# Citations
* [Deep Face Recognition](http://www.robots.ox.ac.uk/~vgg/publications/2015/Parkhi15/parkhi15.pdf) by Parkhi et. al.
* Please check Travis out at https://medium.com/analytics-vidhya/building-a-real-time-emotion-detector-towards-machine-with-e-q-c20b17f89220 or at https://github.com/travistangvh/

# Debugging Journal
* I didn't go to lab this past week because of fatigue, so I couldn't complete the journal the day it was due. Andre is no longer available for Lab 2B, so here I am doing just that.
* I had maybe 6 hours of debugging on this project just trying different software (Firmata, Pyserial) trying to get my code to properly interact with my Arduino display.
* The best approach ultimately ended up laying down a roadmap of small, approachable goals I could tackle 1 by 1 to make it happen, since diving into both libraries just yielded pain. The first step (which took the longest by far) was manipulating a single LED successfully. I learned that you caan't have the Serial Monitor open while using a serial port, or that data may stick around in the Serial buffer so it can be good practice to flush it once you don't need it. For code debugging, knowing how to use StackOverflow for issues related to yours is massively helpful.
