#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

string alphabet = "abcdefghijklmnopqrstuvwxyz";
string URL_START = "<meta property=\"og:url\" content=\"", URL_END = "\"";
string BODY_START = "<body>", BODY_END = "</body>";
string HREF_START = "<a href=\"", HREF_MID = "\"", HREF_END = "</a>";

int solution(string word, vector<string> pages) {
    unordered_map<string, int> map;
    vector<string> urls;
    vector<int> basic_scores;
    vector<int> out_links;
    unordered_map<string, vector<string>> in_links;
    vector<float> link_scores;
    vector<pair<float, int>> ans;

    transform(word.begin(), word.end(), word.begin(), ::tolower);

    for (string page : pages) {
        string url, body;
        vector<string> hrefs;
        int body_cnt = 0;

        int url_start = page.find(URL_START) + URL_START.length();
        int url_end = page.find(URL_END, url_start) - 1;
        url = page.substr(url_start, url_end - url_start + 1);

        int body_start = page.find(BODY_START) + BODY_START.length();
        int body_end = page.find(BODY_END, body_start) - 1;
        body = page.substr(body_start, body_end - body_start + 1);

        int href_start;
        while ((href_start = body.find(HREF_START)) != string::npos) {
            href_start += HREF_START.length();
            int href_mid = body.find(HREF_MID, href_start) - 1;
            int href_end = body.find(HREF_END, href_start) + HREF_END.length();

            hrefs.push_back(body.substr(href_start, href_mid - href_start + 1));
            body = body.substr(0, href_start - HREF_START.length()) + body.substr(href_end + 1);
        }
        transform(body.begin(), body.end(), body.begin(), ::tolower);

        int word_pos = 0;
        while ((word_pos = body.find(word, word_pos)) != string::npos) {
            if (word_pos == 0) {
                word_pos += word.size();
                if (word_pos == body.size()) body_cnt += 1;
                else if (alphabet.find(body[word_pos]) == string::npos) body_cnt += 1;
            }
            else {
                char temp = body[word_pos - 1];
                word_pos += word.size();
                if (alphabet.find(temp) == string::npos) {
                    if (word_pos == body.size()) body_cnt += 1;
                    else if (alphabet.find(body[word_pos]) == string::npos) body_cnt += 1;
                }
            }
        }

        map[url] = urls.size();
        urls.push_back(url);
        basic_scores.push_back(body_cnt);
        out_links.push_back(hrefs.size());
        for (string href : hrefs) in_links[href].push_back(url);
        link_scores.push_back((float) body_cnt / hrefs.size());
    }

    for (int i = 0; i < pages.size(); i++) {
        auto score = (float) basic_scores[i];

        for (auto in : in_links[urls[i]]) {
            int in_idx = map[in];
            score += link_scores[in_idx];
        }

        ans.push_back(make_pair(-score, i));
    }

    sort(ans.begin(), ans.end());

    return ans[0].second;
}

int main() {
//    cout << solution("blind", {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>"});
    cout << solution("Muzi", {"<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>"});

    return 0;
}