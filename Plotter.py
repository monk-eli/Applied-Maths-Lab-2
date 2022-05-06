import numpy as np
from matplotlib import pyplot as pypl


def parabolicFunction(fArgs):
    return fArgs[0] ** 2 + 3 * fArgs[1] ** 2 - 2 * fArgs[0] * fArgs[1] + 1


def parseOutputToFloat(fileName):
    with open(fileName) as file:
        lines = file.readlines()

    floats = []

    for i in range(len(lines)):
        dot = lines[i].split(',')
        dot = [float(j) for j in dot]
        floats.append([])
        for j in range(2):
            floats[i].append(dot[j])

    return floats


def plotResult(dotFloats, labelName, fileName):
    fig, axes = pypl.subplots(nrows=1, ncols=1)
    args = np.meshgrid(np.arange(-10, 10, 0.1), np.arange(-10, 10, 0.1))
    axes.contour(*args, parabolicFunction(args), 50)
    axes.plot(*np.array(dotFloats).T, label=labelName)
    axes.legend()
    pypl.savefig(fileName)


# Conjugate gradient descent and GRStep gradient descent comparison plot
fig, axes = pypl.subplots(nrows=1, ncols=1)
args = np.meshgrid(np.arange(-10, 10, 0.1), np.arange(-10, 10, 0.1))
axes.contour(*args, parabolicFunction(args), 50)
axes.plot(*np.array(parseOutputToFloat("output-gradient/ConjugateGradientDescent")).T,
          label='Метод сопряженных градиентов')
axes.plot(*np.array(parseOutputToFloat("output-gradient/GRStepDescent")).T, label='Метод градиентного спуска')
axes.legend()
pypl.savefig("plots/compare.png")

plotResult(parseOutputToFloat("output-gradient/ConjugateGradientDescent"), "Метод сопряженных градиентов",
           "plots/ConjugateGradient.png")
plotResult(parseOutputToFloat("output-gradient/ConstantStepDescent"), "Градиентный спуск (Константный шаг)",
           "plots/ConstantStep.png")
plotResult(parseOutputToFloat("output-gradient/FibonacciStepDescent"), "Градиентный спуск (Метод Фибоначчи)",
           "plots/FibonacciStep.png")
plotResult(parseOutputToFloat("output-gradient/FractionizeStepDescent"), "Градиентный спуск (Метод дробления шага)",
           "plots/FractionizeStep.png")
plotResult(parseOutputToFloat("output-gradient/GRStepDescent"), "Градиентный спуск (Метод золотого сечения)",
           "plots/GRStep.png")
