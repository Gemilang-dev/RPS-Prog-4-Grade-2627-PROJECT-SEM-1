// Lesson 15: Third-Party Library Integration - Educational Demonstration
#include <iostream>
#include <string>
#include <map>

// Simulating a lightweight Header-Only Third-Party Mini JSON Serializer
namespace MiniJson {
    class Document {
    private:
        std::map<std::string, std::string> attributes;
    public:
        void add(const std::string& key, const std::string& value) {
            attributes[key] = value;
        }

        std::string serialize() const {
            std::string json = "{\n";
            for (auto it = attributes.begin(); it != attributes.end(); ++it) {
                json += "  \"" + it->first + "\": \"" + it->second + "\"";
                auto next = it;
                ++next;
                if (next != attributes.end()) {
                    json += ",";
                }
                json += "\n";
            }
            json += "}";
            return json;
        }
    };
}

int main() {
    std::cout << "====================================================\n";
    std::cout << "  LESSON 15: THIRD-PARTY LIBRARY INTEGRATION DEMO\n";
    std::cout << "====================================================\n\n";

    std::cout << "--- Ingesting and Calling Simulated Header-Only JSON Utility ---\n";
    MiniJson::Document telemetryDoc;
    telemetryDoc.add("device_type", "Virtual Turnstile Microcontroller");
    telemetryDoc.add("firmware_version", "v1.4.2");
    telemetryDoc.add("rfid_status", "ONLINE_LISTENING");
    telemetryDoc.add("encryption", "AES-256");

    std::cout << telemetryDoc.serialize() << "\n\n";

    std::cout << "[PASS] Third-party library successfully integrated and executed!\n";
    return 0;
}
