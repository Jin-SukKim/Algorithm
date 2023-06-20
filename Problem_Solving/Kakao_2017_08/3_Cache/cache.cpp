/*
    3. 캐시(난이도: 하)
    지도개발팀에서 근무하는 제이지는 지도에서 도시 이름을 검색하면 해당 도시와
    관련된 맛집 게시물들을 데이터베이스에서 읽어 보여주는 서비스를 개발하고 있다.
    이 프로그램의 테스팅 업무를 담당하고 있는 어피치는 서비스를 오픈하기 전
    각 로직에 대한 성능 측정을 수행하였는데, 제이지가 작성한 부분 중 데이터베이스에서
    게시물을 가져오는 부분의 실행시간이 너무 오래 걸린다는 것을 알게 되었다.
    어피치는 제이지에게 해당 로직을 개선하라고 닦달하기 시작하였고,
    제이지는 DB 캐시를 적용하여 성능 개선을 시도하고 있지만 캐시 크기를 얼마로 해야
    효율적인지 몰라 난감한 상황이다.

    어피치에게 시달리는 제이지를 도와, DB 캐시를 적용할 때 캐시 크기에 따른
    실행시간 측정 프로그램을 작성하시오.

    입력 형식
        캐시 크기(cacheSize)와 도시이름 배열(cities)을 입력받는다.
        cacheSize는 정수이며, 범위는 0 ≦ cacheSize ≦ 30 이다.
        cities는 도시 이름으로 이뤄진 문자열 배열로, 최대 도시 수는 100,000개이다.
        각 도시 이름은 공백, 숫자, 특수문자 등이 없는 영문자로 구성되며,
        대소문자 구분을 하지 않는다. 도시 이름은 최대 20자로 이루어져 있다.

    출력 형식
        - 입력된 도시이름 배열을 순서대로 처리할 때, "총 실행시간"을 출력한다.

    조건
        - 캐시 교체 알고리즘은 LRU(Least Recently Used)를 사용한다.
        - cache hit일 경우 실행시간은 1이다.
        - cache miss일 경우 실행시간은 5이다.
    입출력 예제

    캐시크기(cacheSize)	    도시이름(cities)	                                                                                            실행시간
    3	                ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	                        50
    3	                ["Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"]	                                21
    2	                ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	60
    5	                ["Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"]	52
    2	                ["Jeju", "Pangyo", "NewYork", "newyork"]	                                                                        16
    0	                ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]	                                                                    25
*/
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

/*
    LRU 의 원리 - LRU 를 구현하기 위해서는 캐시가 가득 찼을때, 
        가장 오랫동안 참조되지 않은 페이지를 찾아서 없애는 과정

    1. 새로운 데이터가 들어온 경우(miss라고 한다)
        a) 캐시에 넣어준다.
        b) 캐시가 가득차있다면, 가장 오래된 데이터를 제거하고 넣어준다.
    2. 존재하는 데이터가 들어온 경우 (Hit이라고 한다.)
        a) 해당 데이터를 꺼낸 뒤 가장 최근 데이터 위치로 보내준다.

    deque는 앞과 끝에서 삽입/제거가 빠르고 다른 위치에서도의 삽입/제거 속도가 괜찮다.
*/
int cacheTime(int cacheSize, std::vector<std::string> cities)
{
    // 저장할 캐시가 없으므로 계속 새로운 데이터가 들어오는 것과 같다.
    // 캐시 사이즈 * miss time(5)
    if (cacheSize == 0)
        return cities.size() * 5;

    std::deque<std::string> cache(cacheSize);
    int time = 0;
    for (auto city : cities)
    {
        auto check = std::find(cache.begin(), cache.end(), city);
        // 새로운 데이터가 들어온 경우(Miss)
        if (check == cache.end())
        {
            // 캐시가 가득차있다면 가장 오래된 데이터를 제거
            if (cache.size() >= cacheSize)
                cache.pop_front();
            cache.push_back(city);
            time += 5;
        }
        // 존재하는 데이터가 들어온 경우(Hit)
        else
        {
            cache.erase(check);
            cache.push_back(city);
            time++;
        }
    }
    return time;
}

int main()
{
    std::vector<std::string> test1 =
    {
        "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"
    };
    cacheTime(3, test1);

    std::vector<std::string> test2 =
    {
        "Jeju", "Pangyo", "Seoul", "NewYork", "LA"
    };
    cacheTime(0, test2);

    std::vector<std::string> test3 =
    {
        "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"
    };
    cacheTime(5, test3);
    return 0;
}