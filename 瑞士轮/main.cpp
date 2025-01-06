#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

// ��������
class Participant {
public:
    std::string name;
    int score;
    int wins;
    int losses;

    Participant(const std::string& n,int ability) : name(n), score(ability), wins(0), losses(0) {}
};

// ����������ģ�������������²����ߵ�����
void simulateMatch(Participant& p1, Participant& p2) {
    bool p1Wins;
    if (p1->score>=p2->score){
        p1Wins=true;
    }
    if (p1->score<p2->score){
        p1Wins=false;
    }

    if (p1Wins) {
        p1.wins += 1;
        p2.losses += 1;
    } else {
        p2.wins += 1;
        p1.losses += 1;
    }
}




// ��ʿ�ֺ���������ģ��һ�ֱ����е����
void simulate_row(vector<Participant> &a,vector<Participant> &b) {
    if(a.size()=0){
        return;
    }
    int num=a[0]->wins;
    // ʹ������������������ݽ����������
    random_device rd;
    mt19937 gen(rd());
    shuffle(a.begin(), a.end(), gen);

    // �������������
    std::vector<std::pair<Participant, Participant>> pairs;
    for (int i = 0; i < a.size(); i += 2) {
        pairs.push_back(std::make_pair(a[i], a[i + 1]));
    }

    // �����Խ��
    for (const auto& pair : pairs) {
        simulateMatch(pair.first,pair.second);
    }



}



// �����ȽϺ��������ڸ��ݻ��ֽ��в����ߵ�����
bool compareParticipants(vector<Participant>) {

    return p1.score > p2.score;
}

int main() {
    // ��ʼ���������б�
    std::vector<Participant> participants;
    participants.push_back(Participant("Player 1",10));
    participants.push_back(Participant("Player 2",10));
    participants.push_back(Participant("Player 3",10));
    participants.push_back(Participant("Player 4",10));
    participants.push_back(Participant("Player 5",10));
    participants.push_back(Participant("Player 6",10));
    participants.push_back(Participant("Player 7",10));
    participants.push_back(Participant("Player 8",10));
    participants.push_back(Participant("Player 9",0));
    participants.push_back(Participant("Player 10",0));
    participants.push_back(Participant("Player 11",0));
    participants.push_back(Participant("Player 12",0));
    participants.push_back(Participant("Player 13",0));
    participants.push_back(Participant("Player 14",0));
    participants.push_back(Participant("Player 15",0));
    participants.push_back(Participant("Player 16",0));

    vector<Participant> num_1;
    vector<Participant> num_2;
    vector<Participant> num_3;

    for(int i=0;i<5;i++){

    }



    // ���ݻ��ֽ�������
    std::sort(participants.begin(), participants.end(), compareParticipants);

    // ����������
    std::cout << "Final Ranking:" << std::endl;
    for (int i = 0; i < participants.size(); ++i) {
        std::cout << i + 1 << ". " << participants[i].name << " (Score: " << participants[i].score << ")" << std::endl;
    }

    return 0;
}
