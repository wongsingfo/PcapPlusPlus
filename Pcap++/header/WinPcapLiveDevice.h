#ifndef PCAPP_WINPCAP_LIVE_DEVICE
#define PCAPP_WINPCAP_LIVE_DEVICE

#ifdef WIN32

#include <PcapLiveDevice.h>

class WinPcapLiveDevice : public PcapLiveDevice
{
	friend class PcapLiveDeviceList;
protected:
	int m_MinAmountOfDataToCopyFromKernelToApplication;

	// c'tor is not public, there should be only one for every interface (created by PcapLiveDeviceList)
	WinPcapLiveDevice(pcap_if_t* iface, bool calculateMTU);
	// copy c'tor is not public
	WinPcapLiveDevice( const WinPcapLiveDevice& other );
	WinPcapLiveDevice& operator=(const WinPcapLiveDevice& other);

public:
	virtual LiveDeviceType getDeviceType() { return WinPcapDevice; }

	bool startCapture(OnPacketArrivesCallback onPacketArrives, void* onPacketArrivesUserCookie, int intervalInSecondsToUpdateStats, OnStatsUpdateCallback onStatsUpdate, void* onStatsUpdateUsrrCookie);
	bool startCapture(int intervalInSecondsToUpdateStats, OnStatsUpdateCallback onStatsUpdate, void* onStatsUpdateUserCookie);
	bool startCapture(RawPacketVector& capturedPacketsVector) { return PcapLiveDevice::startCapture(capturedPacketsVector); }

	virtual int sendPackets(RawPacket* rawPacketsArr, int arrLength);

	bool setMinAmountOfDataToCopyFromKernelToApplication(int size);
	int getMinAmountOfDataToCopyFromKernelToApplication() { return m_MinAmountOfDataToCopyFromKernelToApplication; }
};

#endif // WIN32

#endif /* PCAPP_WINPCAP_LIVE_DEVICE */
