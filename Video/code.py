import cv2
import os

def extract_frames_and_save(video_path, output_dir):
    # 打开视频文件
    cap = cv2.VideoCapture(video_path)

    # 检查视频是否成功打开
    if not cap.isOpened():
        print("Error: Could not open video file.")
        return

    # 创建输出目录
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    frame_count = 0
    save_count = 0

    # 读取视频帧
    while True:
        # 从视频捕捉设备中读取一帧
        ret, frame = cap.read()

        # 检查是否成功读取帧
        if not ret:
            print("End of video.")
            break

        # 仅每五帧保存一张图片
        if frame_count % 5 == 0:
            # 构造输出文件名
            output_file = os.path.join(output_dir, f"frame_{save_count}.jpg")

            # 将当前帧保存为 JPG 文件
            cv2.imwrite(output_file, frame)

            save_count += 1

        frame_count += 1

    # 释放视频捕捉对象
    cap.release()

if __name__ == "__main__":
    # 输入视频文件路径
    input_video_path = 'video/Train.avi'

    # 输出目录路径
    output_directory = 'video/Train.avi_jpg/'

    # 调用函数
    extract_frames_and_save(input_video_path, output_directory)
