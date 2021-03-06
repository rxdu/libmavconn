// MESSAGE SENS_POWER_BOARD support class

#pragma once

namespace mavlink {
namespace ASLUAV {
namespace msg {

/**
 * @brief SENS_POWER_BOARD message
 *
 * Monitoring of power board status
 */
struct SENS_POWER_BOARD : mavlink::Message {
    static constexpr msgid_t MSG_ID = 212;
    static constexpr size_t LENGTH = 46;
    static constexpr size_t MIN_LENGTH = 46;
    static constexpr uint8_t CRC_EXTRA = 242;
    static constexpr auto NAME = "SENS_POWER_BOARD";


    uint64_t timestamp; /*< Timestamp */
    uint8_t pwr_brd_status; /*< Power board status register */
    uint8_t pwr_brd_led_status; /*< Power board leds status */
    float pwr_brd_system_volt; /*< Power board system voltage */
    float pwr_brd_servo_volt; /*< Power board servo voltage */
    float pwr_brd_mot_l_amp; /*< Power board left motor current sensor */
    float pwr_brd_mot_r_amp; /*< Power board right motor current sensor */
    float pwr_brd_servo_1_amp; /*< Power board servo1 current sensor */
    float pwr_brd_servo_2_amp; /*< Power board servo1 current sensor */
    float pwr_brd_servo_3_amp; /*< Power board servo1 current sensor */
    float pwr_brd_servo_4_amp; /*< Power board servo1 current sensor */
    float pwr_brd_aux_amp; /*< Power board aux current sensor */


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
        ss << "  timestamp: " << timestamp << std::endl;
        ss << "  pwr_brd_status: " << +pwr_brd_status << std::endl;
        ss << "  pwr_brd_led_status: " << +pwr_brd_led_status << std::endl;
        ss << "  pwr_brd_system_volt: " << pwr_brd_system_volt << std::endl;
        ss << "  pwr_brd_servo_volt: " << pwr_brd_servo_volt << std::endl;
        ss << "  pwr_brd_mot_l_amp: " << pwr_brd_mot_l_amp << std::endl;
        ss << "  pwr_brd_mot_r_amp: " << pwr_brd_mot_r_amp << std::endl;
        ss << "  pwr_brd_servo_1_amp: " << pwr_brd_servo_1_amp << std::endl;
        ss << "  pwr_brd_servo_2_amp: " << pwr_brd_servo_2_amp << std::endl;
        ss << "  pwr_brd_servo_3_amp: " << pwr_brd_servo_3_amp << std::endl;
        ss << "  pwr_brd_servo_4_amp: " << pwr_brd_servo_4_amp << std::endl;
        ss << "  pwr_brd_aux_amp: " << pwr_brd_aux_amp << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << timestamp;                     // offset: 0
        map << pwr_brd_system_volt;           // offset: 8
        map << pwr_brd_servo_volt;            // offset: 12
        map << pwr_brd_mot_l_amp;             // offset: 16
        map << pwr_brd_mot_r_amp;             // offset: 20
        map << pwr_brd_servo_1_amp;           // offset: 24
        map << pwr_brd_servo_2_amp;           // offset: 28
        map << pwr_brd_servo_3_amp;           // offset: 32
        map << pwr_brd_servo_4_amp;           // offset: 36
        map << pwr_brd_aux_amp;               // offset: 40
        map << pwr_brd_status;                // offset: 44
        map << pwr_brd_led_status;            // offset: 45
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> timestamp;                     // offset: 0
        map >> pwr_brd_system_volt;           // offset: 8
        map >> pwr_brd_servo_volt;            // offset: 12
        map >> pwr_brd_mot_l_amp;             // offset: 16
        map >> pwr_brd_mot_r_amp;             // offset: 20
        map >> pwr_brd_servo_1_amp;           // offset: 24
        map >> pwr_brd_servo_2_amp;           // offset: 28
        map >> pwr_brd_servo_3_amp;           // offset: 32
        map >> pwr_brd_servo_4_amp;           // offset: 36
        map >> pwr_brd_aux_amp;               // offset: 40
        map >> pwr_brd_status;                // offset: 44
        map >> pwr_brd_led_status;            // offset: 45
    }
};

} // namespace msg
} // namespace ASLUAV
} // namespace mavlink
