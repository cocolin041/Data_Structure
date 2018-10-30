#include <iostream>
#include <algorithm>
#include "OfficeHour.h"
using namespace std;

/*
Given the current Office Hour queue and the currently on-duty staffers, return
how long the nth student will need to wait before a Staffer can reach them
Return -1 if there are no staff available to help the nth student

@param queue A queue containing the students currently waiting for help
@param onDutyStaff  A vector of Staffers currently on duty
@param nthStudent   The student for whom we are calculating a wait time
@return             How many minutes the nth student will have to wait before getting help
*/
int waitTime(queue<Student> queue, vector<Staffer> onDutyStaff, int nthStudent) {
    // Your code here!
    int waitingTime = 0;
    vector<int> answeringTime;
    bool staffAvailable = true;

    for (unsigned i = 0; i < onDutyStaff.size(); i++) {
      answeringTime.push_back(0);
    }
    for (int i = 0; i <= nthStudent; ) {
      //check if any staff available
      staffAvailable = false;
      for (unsigned k = 0; k < onDutyStaff.size(); k++) {
        // std::cout << "staff " << k << " has " << onDutyStaff[k].getEnergyLevel() << " energy" << std::endl;
        if (onDutyStaff[k].getEnergyLevel() > 0) {
          staffAvailable = true;
        }
      }
      if (staffAvailable == false) {
        // std::cout << "out of energy" << std::endl;
        return -1;
      } else {
        //get the first available staff to answer the question
        unsigned j = 0;
        while ((answeringTime[j] != 0 || onDutyStaff[j].getEnergyLevel() <= 0) && j != onDutyStaff.size()) {  
            j++;
        }
        //if some staff are not busy
        if (j < onDutyStaff.size() && answeringTime[j] == 0 && onDutyStaff[j].getEnergyLevel() > 0) {

          //get the first student in the queue
          Student firstStudent = queue.front();
          queue.pop();

          //get how many time this staff will need to answer this student
          answeringTime[j] = onDutyStaff[j].answerQuestion(firstStudent.getQuestionType(), firstStudent.getTimeNeeded());
          std::cout << "the staff " << j << " need " <<answeringTime[j] << std::endl;
          i++;
        } else {
          int fastStaffIndex = 0;
          //if all staffs are busy, calculate the waiting time as the smallest time the in the staff queue
          for (unsigned k = 0; k < onDutyStaff.size(); k++) {
            if (onDutyStaff[k].getEnergyLevel() > 0) {
              fastStaffIndex = k;
            }
          }
          
          //get which staff is the first to finish answer question & its spending time
          for (unsigned k = 0; k < onDutyStaff.size(); k++) {
            if (onDutyStaff[k].getEnergyLevel() > 0 && answeringTime[k] < answeringTime[fastStaffIndex]) {
              fastStaffIndex = k;
            }
          }
          waitingTime += answeringTime[fastStaffIndex];
          //deduct time as the smallest waiting time passed
          for (unsigned k = 0; k < answeringTime.size(); k++) {
            if (answeringTime[k] > 0) {
              answeringTime[k] -= answeringTime[fastStaffIndex];
            }
          }
        }
      }
    }
    return waitingTime; 
}
