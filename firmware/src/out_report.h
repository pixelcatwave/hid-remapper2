#ifndef _OUT_REPORT_H_
#define _OUT_REPORT_H_

#include <stdint.h>

// Nuance PowerMic-style 16-bit button mask bits
#define PM_BTN_TRANSCRIBE    0x0001
#define PM_BTN_TABBACKWARD   0x0002
#define PM_BTN_DICTATE       0x0004
#define PM_BTN_TABFORWARD    0x0008
#define PM_BTN_REWIND        0x0010
#define PM_BTN_FASTFORWARD   0x0020
#define PM_BTN_STOPPLAY      0x0040
#define PM_BTN_CUSTOMLEFT    0x0080
#define PM_BTN_ENTERSELECT   0x0100

enum class OutType : int8_t {
    OUTPUT = 0,
    GET_FEATURE = 1,
    SET_FEATURE = 2,
};

void do_queue_out_report(const uint8_t* report, uint16_t len, uint8_t report_id, uint8_t dev_addr, uint8_t interface, OutType type);
void do_queue_get_report(uint8_t report_id, uint8_t dev_addr, uint8_t interface, uint8_t len);
void do_send_out_report();

void get_report_cb(uint8_t dev_addr, uint8_t interface, uint8_t report_id, uint8_t report_type, uint8_t* report, uint16_t len);
void set_report_complete_cb(uint8_t dev_addr, uint8_t interface, uint8_t report_id);

#endif
