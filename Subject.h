#ifndef _SUBJECT_H
#define _SUBJECT_H

#include <vector>

#include "observer.h"

class Subject {
  std::vector<Observer *> observers;

 public:
  void attach(Observer *ob);
  void detach(Observer *ob);
  void notifyObservers();
  virtual ~Subject() = default;
};  // from the course lecture

#endif
