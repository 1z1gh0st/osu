import sys
import math
import numpy as np
import matplotlib

def sigmoid(x):
    return 1 / (1 + exp((-1) * x))

class Layer:
    def __init__(self):
        self.input = None
        self.output = None
        self.weights = None
        self.bias = None

    def feed_forward(inputs):
        return sigmoid(np.dot(inputs, weights) + bias)
