//
//  priorety_queue.h
//  priorety_queue
//
//  Created by Полина Подчуфарова on 07/12/2019.
//  Copyright © 2019 Полина Подчуфарова. All rights reserved.
//

#ifndef priorety_queue_h
#define priorety_queue_h
#include <vector>
#include <iostream>
#include <iterator>
#include <utility>
using namespace std;
namespace Try_To_Be_Smart {
    template <class type_elem,class type_priority>
    class Priority_QueueIt{
    private:
        pair<type_elem,type_priority> *cur;
    public:
        Priority_QueueIt() : cur(0) {}
        Priority_QueueIt(pair<type_elem,type_priority> cur) {this->cur=&cur;}
        Priority_QueueIt(pair<type_elem,type_priority> *cur){this->cur=cur;}
        bool operator!=(const Priority_QueueIt& cur) const{
            return this->cur!=cur;
        }
        bool operator==(const Priority_QueueIt& cur) const{
            return this->cur==cur;
        }
        pair<type_elem,type_priority>& operator *(){
            return *cur;
        }
        pair<type_elem,type_priority>* operator ->(){
            return cur;
        }
         pair<type_elem,type_priority>& operator++(){
           
            return  *++cur;;
        }
    };


template <class type_elem,class type_priority>
class Priorety_Queue {
    friend class Priority_QueueIt<type_elem,type_priority>;
private:
  vector<pair<type_elem,type_priority>> elem;
  vector<unsigned> timeline;
public:
    Priorety_Queue(){}
    Priorety_Queue(const Priorety_Queue& _Q){
        for (int i=0;i<_Q.size();i++){
            elem.push_back(_Q.elem[i]);
            timeline.push_back(_Q.timeline[i]);
        }
    }
    ~Priorety_Queue(){
        elem.clear();
        timeline.clear();
    }
    typedef Priority_QueueIt<type_elem,type_priority> Iterator;
    Iterator begin() const {return Iterator(elem[0]);}
    Iterator end()const {return Iterator(elem[size()-1]);}
                                                                                        
    Priorety_Queue& operator=(const Priorety_Queue& _Q){
        for (int i=0;i<_Q.size();i++){
            elem.push_back(_Q.elem[i]);
            timeline.push_back(_Q.timeline[i]);
        }
        return *this;
    }
    type_elem top() const{
          return elem[0].first;
    }
    size_t size() const{
        return elem.size();
    }
    bool empty () const{
        return elem.empty();
    }
    void push(const type_elem& value1,const type_priority& priority){
        pair<type_elem,type_priority> value;
        value.first=value1;
        value.second=priority;
        int pos=0;
        for (int i=0;i<timeline.size();i++)
            timeline[i]--;
        if (!elem.empty()){
            while (pos<elem.size()){
                if (elem[pos].second<priority||((pos+1)==elem.size())) break;
                pos++;
            }
            if ((timeline[pos]==0)&&(pos<elem.size())) pos++;
			while (elem[pos].second = priority) pos++;
        }
       elem.insert(elem.begin()+pos, value);
      timeline.insert(timeline.begin()+pos, 4);
        
        
    }
    void pop(){
        elem.erase(elem.begin());
        vector<pair<type_elem,type_priority>>(elem).swap(elem);
        timeline.erase(timeline.begin());
        vector<unsigned>(timeline).swap(timeline);
    }
    void  erase_queue(int i) {
        elem.erase(elem.cbegin()+i);
        timeline.erase(timeline.cbegin()+i);
    }
};
   
   
}
#endif /* priorety_queue_h */
