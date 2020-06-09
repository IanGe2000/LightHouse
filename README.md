# LightHouse
4 BITers doing their project on MEcontrol course.  
![image](https://img.shields.io/badge/group_leader-GYA-orange.svg)  
![image](https://img.shields.io/badge/member-LSF-blue.svg)
![image](https://img.shields.io/badge/member-LQY-blue.svg)
![image](https://img.shields.io/badge/member-HCR-blue.svg)  

## Initiation
This project is now based on Raspberry. We want to make an object tracking car system that tracks the displacement of the user by constantly moving itself to maintain constant distance from the object. Along with this function, we could also add in functions such as obstacles-avoiding and IR-locating.

## Framework
```
~/PythonCode
  |
  |__ 主功能包
  |   |__ main_lane_tracking.py
  |   |__ main_object_detection.py
  |   |__ main_obstacle_avoidance.py
  |
  |
  |__ 功能模块
  |   |__ ultrasound.py (超声波检测)
  |   |__ infrared.py (红外线检测)
  |   |__ track.py (赛道检测)
  |   |__ camera.py (摄像头)
  |   |__ move.py (舵机移动)
  |   |__ pc_receiver.py (电脑画面传输)
  |
  |
  |__ object_detection (目标检测)
      |__ visualization_utils (图形检测可视化)
```
## Latest Update
Maybe we can change Tensorflow API but we have no time to do that.  
Hope someone can help us to continue this project.  

## History Update
[2020-06-09]Try to reduce frame rate but there is no much improvement.  
[2020-05-12]Find the way to pick up the characteristic value of person and use it to track a person.  
[2020-05-01]Hardware kit at hand now. Running some basic tests and trying to get into actual work now.  
[2020-04-03]Diving into the readings. Building up some basic concepts, fundamental details and implementations about this thing we're gona make.  
[2020-03-27]Researching phase. Grabing anything that may be useful.  

## Reference Project and Website
https://www.cnblogs.com/MingruiYu/archive/2020/01/12/12184953.html?tdsourcetag=s_pctim_aiomsg  
https://github.com/Mingrui-Yu/RaspberryCar  
对你们表示深深地感谢！  
