package com.yaobin.audio_communication;

public class WaveEncoder {
	public static final double zero_width=1.0/4;
	public static final double one_width=3.0/4;
	public static final double start_width=4.0/5;
	public static final double start_length=MessageOut.start_length;
	public static final double bit_length=MessageOut.bit_length;
	static{   
		System.loadLibrary("AudioCoder");   
	}
	public native static byte[] bit_wave(byte[] wave, int Bit_Data);
	public native static byte[] start_wave(byte[] wave);
}
