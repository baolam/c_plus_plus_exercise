import os
import shutil

PATH = "E:/Excercise/C++/LMH_Giai_Thuat_Lap_Trinh"

objs = os.listdir(PATH)
for obj in objs:
  content = PATH + '/' + obj
  if os.path.isfile(content):
    name, ext = obj.split('.')
    folder_name = PATH + '/' + name
    if not os.path.exists(folder_name):
      os.makedirs(folder_name)
      shutil.move(content, folder_name + '/' + obj)