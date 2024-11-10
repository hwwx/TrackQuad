<!--
 * @Author: hwwx 93569047+hwwx@users.noreply.github.com
 * @Date: 2024-01-11 06:33:03
 * @LastEditors: hwwx 93569047+hwwx@users.noreply.github.com
 * @LastEditTime: 2024-01-11 06:38:50
 * @FilePath: \Master(GS)c:\Users\HWX\Desktop\学习资料\大三上学期\边缘计算\Final\Appendix\Rospkg\ReadMe.md
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
-->
下列是本次实验中所使用到的ROS功能包：

- [MAVROS](https://github.com/mavlink/mavros)用于PX4飞控与ROS的连接
- [vision_to_mavros](https://github.com/thien94/vision_to_mavros)用于t265到PX4的位姿转换
- [Realsense](https://github.com/IntelRealSense/realsense-ros)t265与d435i的官方驱动
- [Yolov5_ros](https://github.com/qq44642754a/Yolov5_ros)用于部署yolo模型以及目标检测
- [usb_cam](https://github.com/ros-drivers/usb_cam)用于输出图像到ROS话题