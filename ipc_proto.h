/*
 * Linux (A53) <-> Zephyr (R5F) ortak IPC protokolu.
 * Bu dosya IKI tarafta da ayni olmali.
 */
#ifndef IPC_PROTO_H
#define IPC_PROTO_H

#include <stdint.h>

#define IPC_PROTO_VERSION  1

/* Komut tipleri */
enum ipc_cmd_type {
	CMD_PING       = 0x00,   /* baglanti testi */
	CMD_LED_SET    = 0x01,   /* value: 0=sondur, 1=yak */
	CMD_LED_GET    = 0x02,   /* LED durumunu sor */
	CMD_MOTOR_SET  = 0x10,   /* id: motor no, value: hedef RPM */
	CMD_MOTOR_STOP = 0x11,   /* id: motor no */
	CMD_STATUS_GET = 0x20,   /* genel durum */
};

/* Cevap kodlari */
enum ipc_resp_status {
	RESP_OK        = 0x00,
	RESP_ERR_CMD   = 0x01,   /* bilinmeyen komut */
	RESP_ERR_ID    = 0x02,   /* gecersiz id */
	RESP_ERR_VALUE = 0x03,   /* gecersiz deger */
	RESP_ERR_VER   = 0x04,   /* protokol versiyonu uyusmuyor */
};

/* Linux -> R5 */
struct ipc_cmd {
	uint8_t  version;
	uint8_t  type;
	uint8_t  id;
	uint8_t  _pad;
	int32_t  value;
} __attribute__((packed));

/* R5 -> Linux */
struct ipc_resp {
	uint8_t  version;
	uint8_t  type;
	uint8_t  status;
	uint8_t  _pad;
	int32_t  value;
} __attribute__((packed));

#endif /* IPC_PROTO_H */
