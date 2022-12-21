# This is a sample Python script.

import torch
# Press Shift+F10 to execute it or replace it with your code.
# Press Double Shift to search everywhere for classes, files, tool windows, actions, and settings.
data=torch.randn(10,10)
isinstance(data,torch.cuda.FloatTensor)
print(isinstance(data,torch.cuda.FloatTensor))
#output:False
data=data.cuda()
isinstance(data,torch.cuda.FloatTensor)
#output:True
print(isinstance(data,torch.cuda.FloatTensor))


# def print_hi(name):
#     # Use a breakpoint in the code line below to debug your script.
#     print(f'Hi, {name}')  # Press Ctrl+F8 to toggle the breakpoint.


# # Press the green button in the gutter to run the script.
# if __name__ == '__main__':
#     print_hi('PyCharm')

# See PyCharm help at https://www.jetbrains.com/help/pycharm/
