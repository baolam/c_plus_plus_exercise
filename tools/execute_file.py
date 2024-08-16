import os

# EXCLUDE = ["codeforces", "vnoi", "LMH_Giai_Thuat_Lap_Trinh", ".git", ".vscode", "tools"]
EXCLUDE = []
PATH = "E:/Excercise/C++/codeforces"

folders = os.listdir(PATH)
for folder in folders:
  if not folder in EXCLUDE:
    tmp = PATH + '/' + folder + '/' + folder
    cpp_file = tmp + '.cpp'
    out_file = tmp + '.exe'
    command = "g++ " + cpp_file + ' -o ' + out_file
    print ("Execute " + folder)
    os.system(command)