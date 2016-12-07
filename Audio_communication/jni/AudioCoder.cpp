#include <jni.h>
#include "com_yaobin_audio_communication_WaveEncoder.h"

#define zero_width		com_yaobin_audio_communication_WaveEncoder_zero_width
#define one_width		com_yaobin_audio_communication_WaveEncoder_one_width
#define	start_width 	com_yaobin_audio_communication_WaveEncoder_start_width
#define start_length	com_yaobin_audio_communication_WaveEncoder_start_length
#define bit_length		com_yaobin_audio_communication_WaveEncoder_bit_length

JNIEXPORT jbyteArray JNICALL Java_com_yaobin_audio_1communication_WaveEncoder_bit_1wave
  (JNIEnv *env, jclass obj, jbyteArray wave, jint bit_data)
{
	jbyte wave_data[bit_length];
	(env)->GetByteArrayRegion(wave,0,bit_length,wave_data);
	if(bit_data==1)
	{
		for(int i=0;i<bit_length;i++)
		{
			if(i<one_width*bit_length)
				wave_data[i]=(jbyte)0x00;
			else
				wave_data[i]=(jbyte)0x7f;
		}
	}
	else
	{
		for(int i=0;i<bit_length;i++)
		{
			if(i<zero_width*bit_length)
				wave_data[i]=(jbyte)0x00;
			else
				wave_data[i]=(jbyte)0x7f;
		}
	}
	(env)->SetByteArrayRegion(wave,0,bit_length,wave_data);
	return wave;
}

JNIEXPORT jbyteArray JNICALL Java_com_yaobin_audio_1communication_WaveEncoder_start_1wave
  (JNIEnv *env, jclass obj, jbyteArray wave)
{
	jbyte wave_data[start_length];
	(env)->GetByteArrayRegion(wave,0,start_length,wave_data);
	for(int i=0;i<start_length;i++)
	{
		if(i<start_width*start_length)
			wave_data[i]=(jbyte)0x00;
		else
			wave_data[i]=(jbyte)0x7f;
	}
	(env)->SetByteArrayRegion(wave,0,start_length,wave_data);
	return wave;
}
