// MESSAGE GPS_RTCM_DATA support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief GPS_RTCM_DATA message
 *
 * WORK IN PROGRESS! RTCM message for injecting into the onboard GPS (used for DGPS)
 */
struct GPS_RTCM_DATA : mavlink::Message {
    static constexpr msgid_t MSG_ID = 233;
    static constexpr size_t LENGTH = 182;
    static constexpr size_t MIN_LENGTH = 182;
    static constexpr uint8_t CRC_EXTRA = 35;
    static constexpr auto NAME = "GPS_RTCM_DATA";


    uint8_t flags; /*< LSB: 1 means message is fragmented */
    uint8_t len; /*< data length */
    std::array<uint8_t, 180> data; /*< RTCM message (may be fragmented) */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  flags: " << +flags << std::endl;
        ss << "  len: " << +len << std::endl;
        ss << "  data: [" << to_string(data) << "]" << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << flags;                         // offset: 0
        map << len;                           // offset: 1
        map << data;                          // offset: 2
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> flags;                         // offset: 0
        map >> len;                           // offset: 1
        map >> data;                          // offset: 2
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
