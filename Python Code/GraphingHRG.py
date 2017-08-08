from pyqtgraph.Qt import QtGui, QtCore
import pyqtgraph as pg

import collections
import random
import time
import math
import numpy as np
import serial

ser = serial.Serial('/dev/cu.usbmodem1145981',9600)
data = [] #data array of the sensor readings


class DynamicPlotter():

    def __init__(self, sampleinterval=0.1, timewindow=15., size=(600,350)):
        # Data settings
        self._interval = int(sampleinterval*1000)
        self._bufsize = int(timewindow/sampleinterval)
        self.databuffer = collections.deque([0.0]*self._bufsize, self._bufsize)
        self.databuffer2 = collections.deque([0.0] * self._bufsize, self._bufsize)
        self.databuffer3 = collections.deque([0.0] * self._bufsize, self._bufsize)
        self.databuffer4 = collections.deque([0.0] * self._bufsize, self._bufsize)
        self.databuffer5 = collections.deque([0.0] * self._bufsize, self._bufsize)
        self.databuffer6 = collections.deque([0.0] * self._bufsize, self._bufsize)
        self.x = np.linspace(-timewindow, 0.0, self._bufsize)
        self.y = np.zeros(self._bufsize, dtype=np.float)
        self.x2 = np.linspace(-timewindow, 0.0, self._bufsize)
        self.y2 = np.zeros(self._bufsize, dtype=np.float)
        self.x3 = np.linspace(-timewindow, 0.0, self._bufsize)
        self.y3 = np.zeros(self._bufsize, dtype=np.float)
        self.x4 = np.linspace(-timewindow, 0.0, self._bufsize)
        self.y4 = np.zeros(self._bufsize, dtype=np.float)
        self.x5 = np.linspace(-timewindow, 0.0, self._bufsize)
        self.y5 = np.zeros(self._bufsize, dtype=np.float)
        self.x6 = np.linspace(-timewindow, 0.0, self._bufsize)
        self.y6 = np.zeros(self._bufsize, dtype=np.float)
        ############Plot settings###########
        self.app = QtGui.QApplication([])
        #Plot 1
        self.plt = pg.plot(title='Sensor A')
        self.plt.resize(*size)
        self.plt.showGrid(x=True, y=True)
        self.plt.setLabel('left', 'amplitude', 'V')
        self.plt.setLabel('bottom', 'time', 's')
        #Plot 2
        self.plt2 = pg.plot(title="Sensor B")
        self.plt2.resize(*size)
        self.plt2.showGrid(x=True, y=True)
        self.plt2.setLabel('left', 'amplitude', 'V')
        self.plt2.setLabel('bottom', 'time', 's')
        #Plot 3
        self.plt3 = pg.plot(title="Sensor C")
        self.plt3.resize(*size)
        self.plt3.showGrid(x=True, y=True)
        self.plt3.setLabel('left', 'amplitude', 'V')
        self.plt3.setLabel('bottom', 'time', 's')
        # Plot 4
        self.plt4 = pg.plot(title="Sensor D")
        self.plt4.resize(*size)
        self.plt4.showGrid(x=True, y=True)
        self.plt4.setLabel('left', 'amplitude', 'V')
        self.plt4.setLabel('bottom', 'time', 's')
        # Plot 5
        self.plt5 = pg.plot(title="Sensor E")
        self.plt5.resize(*size)
        self.plt5.showGrid(x=True, y=True)
        self.plt5.setLabel('left', 'amplitude', 'V')
        self.plt5.setLabel('bottom', 'time', 's')
        # Plot 6
        self.plt6 = pg.plot(title="Sensor F")
        self.plt6.resize(*size)
        self.plt6.showGrid(x=True, y=True)
        self.plt6.setLabel('left', 'amplitude', 'V')
        self.plt6.setLabel('bottom', 'time', 's')
        ##################Curves##################
        self.curve = self.plt.plot(self.x, self.y, pen=(255,0,0))
        self.curve2 = self.plt2.plot(self.x2, self.y2, pen=(0,255,0))
        self.curve3 = self.plt.plot(self.x3, self.y3, pen=(0, 0, 255))
        self.curve3 = self.plt2.plot(self.x4, self.y4, pen=(255, 255, 0))
        self.curve5 = self.plt.plot(self.x5, self.y5, pen=(0, 255, 255))
        self.curve6 = self.plt2.plot(self.x6, self.y6, pen=(255, 200, 255))
        # QTimer
        self.timer = QtCore.QTimer()
        self.timer.timeout.connect(self.updateplot)
        self.timer.start(self._interval)
    #functions to recieve the and parse the data
    def getdata(self):
        arduinoString = ser.readline().decode()
        data = arduinoString.split(',')
        print(arduinoString)
        new = data[0]
        return new
    def getdata2(self):
        arduinoString = ser.readline().decode()
        data = arduinoString.split(',')
        new = data[1]
        return new
    def getdata3(self):
        arduinoString = ser.readline().decode()
        data = arduinoString.split(',')
        print(arduinoString)
        new = data[2]
        return new
    def getdata4(self):
        arduinoString = ser.readline().decode()
        data = arduinoString.split(',')
        new = data[3]
        return new
    def getdata5(self):
        arduinoString = ser.readline().decode()
        data = arduinoString.split(',')
        print(arduinoString)
        new = data[4]
        return new
    def getdata6(self):
        arduinoString = ser.readline().decode()
        data = arduinoString.split(',')
        new = data[5]
        return new

    def updateplot(self):
        self.databuffer.append( self.getdata() )
        self.databuffer2.append(self.getdata2())
        self.databuffer3.append(self.getdata3())
        self.databuffer4.append(self.getdata4())
        self.databuffer5.append(self.getdata5())
        self.databuffer6.append(self.getdata6())
        self.y[:] = self.databuffer
        self.y2[:] = self.databuffer2
        self.y3[:] = self.databuffer3
        self.y4[:] = self.databuffer4
        self.y5[:] = self.databuffer5
        self.y6[:] = self.databuffer6
        self.curve.setData(self.x, self.y)
        self.curve2.setData(self.x2, self.y2)
        self.curve3.setData(self.x3, self.y3)
        self.curve4.setData(self.x4, self.y4)
        self.curve5.setData(self.x5, self.y5)
        self.curve6.setData(self.x6, self.y6)
        self.app.processEvents()

    def run(self):
        self.app.exec_()

if __name__ == '__main__':

    m = DynamicPlotter(sampleinterval=0.05, timewindow=10.)
    m.run()