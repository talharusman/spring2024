#include<iostream>
#include<vector>
using namespace std;

class Post {
public:
    int post_id;
    string Post_Content;
    int like;
    vector<string> comments;
    int view;

    Post(int Post_id, string Post_content) : post_id(Post_id), Post_Content(Post_content), like(0), view(0) {}

    void addComment(string comment) {
        comments.push_back(comment);
    }

    void likePost() {
        like++;
    }
    void ViewPost(){
        view++;
    }

    void display() {
        cout << "Post ID: " << post_id << endl;
        cout << "Content: " << Post_Content << endl;
        cout << "Likes: " << like << endl;
        cout << "Views: " << view << endl;
        cout << "Comments (" << comments.size() << "):" << endl;
        for (const auto& comment : comments) {
            cout << "- " << comment << endl;
        }
        cout << endl;
    }
};

class User {
    string user_Name;
    string password;
    string Email;
public:
    User(string name, string pass, string mail) : user_Name(name), password(pass), Email(mail) {}

    string getName() {
        return user_Name;
    }

    bool verifyUser(const string& inputPass) {
        return inputPass == password;
    }
};

class RegularUser : public User {
    static const int Max_post = 5;
    int FeedSize = 0;
    static const int MAX_FEED = 10;
    Post* Feed[MAX_FEED];
public:
    RegularUser(string UserName, string Pass, string mail) : User(UserName, Pass, mail) {}

    void addToFeed(Post* newFeed) {
        if (FeedSize < Max_post) {
            Feed[FeedSize] = newFeed;
            ++FeedSize;
            cout << "Post added to Feed." << endl << endl;
        }
        else {
            cout << "You have reached the maximum number of posts" << endl;
        }
    }

    // Display all feeds for this user.
    void viewFeed() {
        cout << "\nFeed for user " << getName() << ":" << endl;
        for (int i = 0; i < FeedSize; i++) {
            Feed[i]->display();
        }
    }
};

class BusinessUser : public User {
    static const int Max_post = 10;
    int promoted_Posts_Count = 0;
public:
    BusinessUser(string name, string pass, string mail) : User(name, pass, mail) {}

    void promotePost(Post& post) {
        if (promoted_Posts_Count < Max_post) {
            cout << "Your Post promoted successfully." << endl;
            post.likePost();
            post.ViewPost();
            ++promoted_Posts_Count;
        }
        else {
            cout << "You have already promoted max allowed number of posts." << endl;
        }
    }
};



int main(int argc, char const* argv[]) {
    // Create Users
    RegularUser regularUser("Regular", "pass123", "regular@example.com");
    BusinessUser businessUser("Business", "pass456", "business@example.com");

    // Create Posts
    Post post1(1, "This is the first post.");
    Post post2(2, "Another post for testing.");

    // Add posts to feed
    regularUser.addToFeed(&post1);
    regularUser.addToFeed(&post2);

    // View Regular User's feed
    regularUser.viewFeed();

    // Promote a post as Business User
    businessUser.promotePost(post1);

    // Display promoted post
    post1.display();

    return 0;
}
