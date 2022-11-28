#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <iostream>
#include <vector>

#include "Board.h"
#include "observer.h"
#include "piece.h"

class Observer;

class Subject {
  std::vector<Observer *> observers;

 public:
  void attach(Observer *o);
  void detach(Observer *o);
  void notifyObservers();
  virtual char getState(int row, int col) const = 0;
  virtual ~subject() = default;
}