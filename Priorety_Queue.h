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
	template <class type_elem, class type_priority>
	class Priority_QueueIt {
	private:
		pair<type_elem, type_priority>* cur;
	public:
		Priority_QueueIt() : cur(0) {}
		Priority_QueueIt(pair<type_elem, type_priority> cur) { this->cur = &cur; }
		Priority_QueueIt(pair<type_elem, type_priority>* cur) { this->cur = cur; }
		bool operator!=(const Priority_QueueIt& cur) const {
			return this->cur != cur;
		}
		bool operator==(const Priority_QueueIt& cur) const {
			return this->cur == cur;
		}
		pair<type_elem, type_priority>& operator *() {
			return *cur;
		}
		pair<type_elem, type_priority>* operator ->() {
			return cur;
		}
		pair<type_elem, type_priority>& operator++() {

			return  *++cur;;
		}
	};


	template <class type_elem, class type_priority>
	class Priorety_Queue {
		friend class Priority_QueueIt<type_elem, type_priority>;
	private:
		vector<pair<type_elem, type_priority>> elem;
		vector<int> timeline;
	public:
		Priorety_Queue() {}
		Priorety_Queue(const Priorety_Queue& _Q) {
			for (int i = 0; i < _Q.size(); i++) {
				elem.push_back(_Q.elem[i]);
			}
		}
		~Priorety_Queue() {
			elem.clear();
		}
		typedef Priority_QueueIt<type_elem, type_priority> Iterator;
		Iterator begin() const { return Iterator(elem[0]); }
		Iterator end()const { return Iterator(elem[size() - 1]); }

		Priorety_Queue& operator=(const Priorety_Queue& _Q) {
			for (int i = 0; i < _Q.size(); i++) {
				elem.push_back(_Q.elem[i]);
			}
			return *this;
		}
		type_elem top() const {
			return elem[0].first;
		}
		size_t size() const {
			return elem.size();
		}
		bool empty() const {
			return elem.empty();
		}
		void push(const type_elem& value1, const type_priority& priority) {
			pair<type_elem, type_priority> value;
			value.first = value1;
			value.second = priority;
			int pos = 0;
			if (!elem.empty()) {
				while (pos < elem.size()) {
					if (timeline[pos] > priority ) break;
					pos++;
				}
			}
			elem.insert(elem.begin() + pos, value);
			if (elem[pos].first.Summoner != nullptr)
				timeline.insert(timeline.begin() + pos, elem[pos].first.Summoner->get_initiative());
			if (elem[pos].first.Troop != nullptr)
				timeline.insert(timeline.begin() + pos, elem[pos].first.Troop->get_initiative());

		}
		void pop() {
			for (int i = 0; i < elem.size(); i++) {
				timeline[i]--;
			}
			elem.erase(elem.begin());
			vector<pair<type_elem, type_priority>>(elem).swap(elem);
			timeline.erase(timeline.begin());
			vector<int>(timeline).swap(timeline);
		}
		void  erase_queue(int i) {
			elem.erase(elem.cbegin() + i);
			timeline.erase(timeline.begin() + i);
		}
		void show() {
			for (int i = 0; i < elem.size(); i++) {
				if (elem[i].first.Troop == nullptr) {
					cout << "Summoner: " << elem[i].first.Summoner->get_name() << ". Initiative: " << timeline[i];
					cout << endl;
				}
				if (elem[i].first.Troop != nullptr) {
					cout << "Sum: " << elem[i].first.Summoner->get_name() << " his " << typeid(*elem[i].first.Troop).name() << " : " << elem[i].first.Troop->get_creature().get_name() << ". Initiative: " << timeline[i];
					cout << endl;
				}
			}
		}
	};


}
#endif /* priorety_queue_h */
