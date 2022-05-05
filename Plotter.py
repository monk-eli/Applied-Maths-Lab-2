import numpy as np
from matplotlib import pyplot as pypl


def parabolicFunction(fArgs):
    return fArgs[0] ** 2 + 3 * fArgs[1] ** 2 - 2 * fArgs[0] * fArgs[1] + 1


with open('output-gradient/GRStepDescent') as gr:
    linesGR = gr.readlines()

floatsGR = []

for i in range(len(linesGR)):
    dot = linesGR[i].split(',')
    dot = [float(j) for j in dot]
    floatsGR.append([])
    for j in range(2):
        floatsGR[i].append(dot[j])

with open('output-gradient/ConjugateGradientDescent') as CGD:
    linesCGD = CGD.readlines()

floatsCGD = []

for i in range(len(linesCGD)):
    dot = linesCGD[i].split(',')
    dot = [float(j) for j in dot]
    floatsCGD.append([])
    for j in range(2):
        floatsCGD[i].append(dot[j])


fig, axes = pypl.subplots(nrows=1, ncols=1)
args = np.meshgrid(np.arange(-10, 10, 0.1), np.arange(-10, 10, 0.1))
axes.contour(*args, parabolicFunction(args), 10)
axes.plot(*np.array(floatsCGD).T, label='Метод сопряженных градиентов')
axes.plot(*np.array(floatsGR).T, label='Метод градиентного спуска')
axes.legend()
pypl.savefig("plot.png")
