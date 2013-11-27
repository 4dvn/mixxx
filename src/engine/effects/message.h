#ifndef MESSAGE_H
#define MESSAGE_H

#include "util/fifo.h"

struct AddEffectChainSlotRequest {
    int iChainNumber;
};

struct RemoveEffectChainSlotRequest {
    int iChainNumber;
};

struct LoadEffectChainToSlotRequest {
    int iChainNumber;
};

struct EngineEffectsManagerRequest {
    enum MessageType {
        ADD_EFFECT_CHAIN_SLOT_REQUEST,
        REMOVE_EFFECT_CHAIN_SLOT_REQUEST,
        ADD_EFFECT_CHAIN_REQUEST,
        REMOVE_EFFECT_CHAIN_REQUEST,
    };
    MessageType m_type;
    qint64 request_id;
};

struct EngineEffectsManagerResponse {
    enum MessageType {
        ADD_EFFECT_CHAIN_SLOT_RESPONSE,
        REMOVE_EFFECT_CHAIN_SLOT_RESPONSE,
        ADD_EFFECT_CHAIN_RESPONSE,
        REMOVE_EFFECT_CHAIN_RESPONSE,
    };
    MessageType m_type;
    qint64 request_id;
};

// For communicating from the main thread to the EngineEffectsManager.
typedef MessagePipe<EngineEffectsManagerRequest,
                    EngineEffectsManagerResponse> EffectsRequestPipe;
// For communicating from the EngineEffectsManager to the main thread.
typedef MessagePipe<EngineEffectsManagerResponse,
                    EngineEffectsManagerRequest> EffectsResponsePipe;


#endif /* MESSAGE_H */
