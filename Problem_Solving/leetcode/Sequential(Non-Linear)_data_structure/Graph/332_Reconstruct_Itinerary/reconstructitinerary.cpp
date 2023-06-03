/*
    332. Reconstruct Itinerary
        You are given a list of airline tickets
        where tickets[i] = [fromi, toi] represent the departure
        and the arrival airports of one flight.
        Reconstruct the itinerary in order and return it.

        All of the tickets belong to a man who departs from "JFK",
        thus, the itinerary must begin with "JFK".
        If there are multiple valid itineraries,
        you should return the itinerary that has
        the smallest lexical order when read as a single string.

        For example, the itinerary ["JFK", "LGA"] has a smaller lexical
        order than ["JFK", "LGB"].
        You may assume all tickets form at least one valid itinerary.
        You must use all the tickets once and only once.

    Example 1:
        Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
        Output: ["JFK","MUC","LHR","SFO","SJC"]
        Example 2:


        Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
        Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
        Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger in lexical order.

    Constraints:
        1 <= tickets.length <= 300
        tickets[i].length == 2
        fromi.length == 3
        toi.length == 3
        fromi and toi consist of uppercase English letters.
        fromi != toi
*/
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

void dfs(std::unordered_map<std::string, std::multiset<std::string>>& graph,
std::vector<std::string>& route, std::string airport)
{
    while (graph[airport].size())
    {   
        std::string next = *graph[airport].begin();
        graph[airport].erase(graph[airport].begin());
        dfs(graph, route, next);
    }
    route.push_back(airport);
}

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> &tickets)
{
    // map으로 선언해 string key값으로 다음 경로를 찾고
    // multiset으로 한개의 key에 여러 elements를 오름차순으로 정렬해 저장할 수 있게 해준다.
    // multimap은 한개의 key에 여러값을 저장할 수 있지만 정렬을 할 수는 없다.
    std::unordered_map<std::string, std::multiset<std::string>> graph;

    for (auto ticket : tickets)
    {
        graph[ticket[0]].insert(ticket[1]);
    }

    std::vector<std::string> route;
    // 항상 JFK 공항에서 출발
    dfs(graph, route, "JFK");

    return std::vector<std::string>(route.rbegin(), route.rend());
}


int main() {
    std::vector<std::vector<std::string>> tickets = {
        {"EZE","AXA"},{"TIA","ANU"},{"ANU","JFK"},{"JFK","ANU"},{"ANU","EZE"},{"TIA","ANU"},{"AXA","TIA"},{"TIA","JFK"},{"ANU","TIA"},{"JFK","TIA"}
    };

    findItinerary(tickets);


    return 0;
}
