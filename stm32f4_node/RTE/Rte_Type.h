#ifndef RTE_TYPE_H_
#define RTE_TYPE_H_

typedef struct {
    float temperature;
    float humidity;
} SensorDataType;

typedef enum {
    RTE_E_OK = 0,
    RTE_E_NOT_OK
} Rte_StatusType;

#endif /* RTE_TYPE_H_ */
