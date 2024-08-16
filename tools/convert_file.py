import os
import shutil

PATH = "E:/Excercise/C++/vnoi"
CREATE_FOLDER = False

objs = os.listdir(PATH)
for obj in objs:
  content = PATH + '/' + obj
  if os.path.isfile(content):
    name, ext = obj.split('.')
    folder_name = PATH + '/' + name
    if not os.path.exists(folder_name):
      os.makedirs(folder_name)
    if not CREATE_FOLDER:
      shutil.move(content, folder_name + '/' + obj)