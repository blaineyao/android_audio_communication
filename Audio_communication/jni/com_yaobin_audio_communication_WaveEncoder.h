/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_yaobin_audio_communication_WaveEncoder */

#ifndef _Included_com_yaobin_audio_communication_WaveEncoder
#define _Included_com_yaobin_audio_communication_WaveEncoder
#ifdef __cplusplus
extern "C" {
#endif
#undef com_yaobin_audio_communication_WaveEncoder_zero_width
#define com_yaobin_audio_communication_WaveEncoder_zero_width 0.25
#undef com_yaobin_audio_communication_WaveEncoder_one_width
#define com_yaobin_audio_communication_WaveEncoder_one_width 0.75
#undef com_yaobin_audio_communication_WaveEncoder_start_width
#define com_yaobin_audio_communication_WaveEncoder_start_width 0.8
#undef com_yaobin_audio_communication_WaveEncoder_start_length
#define com_yaobin_audio_communication_WaveEncoder_start_length 2205
#undef com_yaobin_audio_communication_WaveEncoder_bit_length
#define com_yaobin_audio_communication_WaveEncoder_bit_length 1102
/*
 * Class:     com_yaobin_audio_communication_WaveEncoder
 * Method:    bit_wave
 * Signature: ([BI)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_yaobin_audio_1communication_WaveEncoder_bit_1wave
  (JNIEnv *, jclass, jbyteArray, jint);

/*
 * Class:     com_yaobin_audio_communication_WaveEncoder
 * Method:    start_wave
 * Signature: ([B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_yaobin_audio_1communication_WaveEncoder_start_1wave
  (JNIEnv *, jclass, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif
