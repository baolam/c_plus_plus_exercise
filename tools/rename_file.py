import os
import shutil

PATH = "E:/Excercise/C++/codeforces"
REMOVED_EXTENSIONS = ["cbp", "layout", "depend"]
# REMOVED_FOLDER = ["bin", "obj"]

objs = os.listdir(PATH)

for obj in objs:
  current_folder = PATH + '/' + obj
  for tmp in os.listdir(current_folder):
    _path = current_folder + '/' + tmp
    if os.path.isfile(_path):
      __, ext = tmp.split('.')
      if ext in REMOVED_EXTENSIONS:
        os.remove(_path)
      else:
        new_file = current_folder + '/' + obj + '.cpp'
        if not os.path.exists(new_file):
          os.rename(_path, current_folder + '/' + obj + '.cpp')
    else:
      shutil.rmtree(_path)