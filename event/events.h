#ifndef _EVENTS_H
#define _EVENTS_H

#include <iostream>
#include <vector>

class Empty{};

template <typename EventAction>
class EventResponser{
public:
    EventResponser(): actor(nullptr), action(nullptr){}
    EventResponser(Empty* actor, EventAction* action): actor(actor), action(action){}
    friend bool operator == (const EventResponser& e1, const EventResponser& e2){
        return e1.actor == e2.actor && *e1.action == *e2.action;
    }

    Empty* actor;
    EventAction* action;
};

template <typename EventAction>
class Event{
public:
    typedef std::vector<EventResponser<EventAction> > EventResponsers;
    typedef typename std::vector<EventResponser<EventAction> >::iterator EventIterator;

    ~Event(){
        for (EventIterator it = ers.begin(); it != ers.end(); ++it){
            delete it->action;
            it->action = nullptr;
        }
    }

    EventResponsers& getEventResponsers(){
        return ers;
    }

    template <typename Responser, typename Action>
    void bind(Responser* actor, Action action){
        Action* act = new Action(action);
        EventResponser<EventAction> er((Empty*)actor, (EventAction*)act);
        bool unbound = true;
        for (EventIterator it = ers.begin(); it != ers.end(); ++it){
            if (*it == er){
                unbound = false;
                break;
            }
        }
        if (unbound) ers.push_back(er);
        else delete er.action;
    }

    template <typename Responser, typename Action>
    void unbind(Responser* actor, Action action){
        Action* act = new Action(action);
        EventResponser<EventAction> er((Empty*)actor, (EventAction*)act);
        for (EventIterator it = ers.begin(); it != ers.end(); ++it){
            if (*it == er){
                ers.erase(it);
                delete it->action;
                break;
            }
        }
        delete er.action;
    }
private:
    EventResponsers ers;
};

typedef void (Empty::*ValueChanged)(int value, void * tag);
class Trigger{
public:
    void setData(int v, void * tag){
        if (data == v) return;
        data = v;
        Event<ValueChanged>::EventResponsers ers = value_changed.getEventResponsers();
        if (ers.empty()) return;
        Event<ValueChanged>::EventIterator it;
        for (it = ers.begin(); it != ers.end(); ++it){
            ((it->actor)->*(*(it->action)))(v, tag);
        }
    }

    Event<ValueChanged> value_changed;
private:
    int data;
};

class Actor{
public:
    void Listen(Trigger* trigger){
        trigger->value_changed.bind(this, &Actor::OnValueChanged);
    }

    void UnListen(Trigger* trigger){
        trigger->value_changed.unbind(this, &Actor::OnValueChanged);
    }

    void OnValueChanged(int v, void * tag){
        std::cout << "value changed data = " << v << std::endl;
    }
};

#endif