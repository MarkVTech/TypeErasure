#pragma once

#include <vector>
#include <string>

class ImmutableBuffer;
class Register32Bits;

using FieldStrings = std::vector<std::string_view>;

/**
 * @brief The NMEAExtractionStream class is used to extract field data from an NMEAMessage.
 */
class NMEAExtractionStream
{
public:
    NMEAExtractionStream() = delete;

    explicit NMEAExtractionStream(const ImmutableBuffer &nmeaMessage);

    /// @todo delete copy and move

    std::string getTalker() const;

    std::string getMessage() const;

    bool numberOfFields() const;

    bool isChecksumValid() const;

    void reset();

    const NMEAExtractionStream& operator>>(int& value);

    const NMEAExtractionStream& operator>>(unsigned int& value);

    const NMEAExtractionStream& operator>>(double& value);

    const NMEAExtractionStream& operator>>(Register32Bits& value);

    const NMEAExtractionStream& operator>>(std::string& value);

private:
    const ImmutableBuffer& mNMEAMessage;
    bool mChecksumValidFlag {false};

    FieldStrings mFields;

    unsigned int mChecksum {0};

    /**
     * @brief mTalker NMEA talker, which is 2 bytes. SSO will kick in, so std::string is okay here.
     */
    std::string mTalker;

    /**
     * @brief mMessage NMEA message, which is 3 bytes. SSO will kick in, so std::string is okay here.
     */
    std::string mMessage;

    uint16_t mFieldIdx{1};

    /**
     * @brief _extractPayload returns a view that includes only the actual NMEA payload fields.
     * @param nmeaMessage A complete NMEA message: $<talker><message>,<f1>,<f2>,<f3>,...,<fn>,*<checksum>
     */
    void _extractPayload(const char* nmeaMessage);
};
