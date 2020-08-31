/*
 * Find robots count (users with large events count)
 */

#include <iostream>
#include <deque>
#include <map>

using namespace std;

class RobotStatistics
{
  int m_timeRange;
  int m_nEvent;
  map<int, deque<unsigned int>> m_userEvent;
 
public:
  RobotStatistics(int t, int e) : m_timeRange(t), m_nEvent(e){}

  void OnEvent(unsigned int now, int userId)
  {
      deque<unsigned int>& d = m_userEvent[userId];
      d.push_back(now);
      cutTail(d, now);
  }

  int GetRobotCount(unsigned int now)
  {
     int nUser = 0;
     //for(auto&[user, d] : m_userEvent) // need --std=c++17
     for(auto& x : m_userEvent)
     {
        uint user = x.first;
        deque<unsigned int> d = x.second;
        cutTail(d, now);
        if(d.size() > m_nEvent)
           ++nUser;
     }
     return nUser;
  }
private:
  void cutTail(deque<unsigned int>& d, unsigned int now)
  {
    auto it = d.begin();
    while(it != d.end() && !isInRange(now, *it))
          it = d.erase(it);
  }

  bool isInRange(unsigned int t1, unsigned int t2)
  {
     return (t1 - t2) < m_timeRange;
  }

};

main() {
  int window_size, events_max_count;
  cin >> window_size >> events_max_count;

  RobotStatistics rs(window_size, events_max_count);
  while (1) {
    int time, user_id;
    cin >> time >> user_id;
    rs.OnEvent(time, user_id);
    cout << rs.GetRobotCount(time) << endl;
  }
}
