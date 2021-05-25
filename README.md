# For ENGR 40M Grading:
All of the direct implementation is going to be in `ard.py`, `emotion_webcam_demo.py`, and `display.ino`, in `../src`but feel free to browse other aspects I used from Travis. I kept his Git history for sake of full transparency and to fully uphold the spirit of the Stanford Honor Code.

# Face Classification 
The following repository is a real-time face detection and emotion classification model.
Credit goes to Travis Tang for the original design and guide for implementation.
<p align="center">
    <img width="320" height="300" src="https://github.com/roshanswaroop/emotion-detection/blob/master/images/IMG_2719.png">
    <img width="320" height="240" src="https://raw.githubusercontent.com/travistangvh/emotion-detection-in-real-time/master/images/demo1.gif">
    <img width="320" height="240" src="https://raw.githubusercontent.com/travistangvh/emotion-detection-in-real-time/master/images/demo2.gif">
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
`pip install -r ../REQUIREMENTS.txt` It may not work at first, so Google alternate versions if pip is giving trouble.

* Download pretrained model and weight `trained_vggface.h5` from [here](https://drive.google.com/file/d/1Wv_Z4lAa7BgYqSAeceK9TxJNfwoLTwKy/view?usp=sharing).

* Place `trained_vggface.h5` into `../datasets/trained_models/`.
* Upload `display.ino` to your Arduino Uno. You will need access to Stanford ENGR40M's Lab 2A handout to build the hardware.

* Run `emotion_webcam_demo.py` using `python3 emotion_webcam_demo.py`

# Citations
* [Deep Face Recognition](http://www.robots.ox.ac.uk/~vgg/publications/2015/Parkhi15/parkhi15.pdf) by Parkhi et. al.
* Please check Travis out at https://medium.com/analytics-vidhya/building-a-real-time-emotion-detector-towards-machine-with-e-q-c20b17f89220 or at https://github.com/travistangvh/
