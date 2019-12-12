package com.academy.contracts;

import java.math.BigInteger;
import java.util.Arrays;
import org.web3j.abi.TypeReference;
import org.web3j.abi.datatypes.Function;
import org.web3j.abi.datatypes.Type;
import org.web3j.abi.datatypes.Utf8String;
import org.web3j.abi.datatypes.generated.Bytes32;
import org.web3j.crypto.Credentials;
import org.web3j.protocol.Web3j;
import org.web3j.protocol.core.RemoteCall;
import org.web3j.tx.Contract;
import org.web3j.tx.TransactionManager;
import org.web3j.tx.gas.ContractGasProvider;

/**
 * <p>Auto generated code.
 * <p><strong>Do not modify!</strong>
 * <p>Please use the <a href="https://docs.web3j.io/command_line.html">web3j command line tools</a>,
 * or the org.web3j.codegen.SolidityFunctionWrapperGenerator in the 
 * <a href="https://github.com/web3j/web3j/tree/master/codegen">codegen module</a> to update.
 *
 * <p>Generated with web3j version 4.1.0.
 */
public class StringUtils extends Contract {
    private static final String BINARY = "608060405234801561001057600080fd5b50610343806100206000396000f3006080604052600436106100565763ffffffff7c01000000000000000000000000000000000000000000000000000000006000350416639201de55811461005b57806394e8767d146100e8578063e939567914610112575b600080fd5b34801561006757600080fd5b5061007360043561012a565b6040805160208082528351818301528351919283929083019185019080838360005b838110156100ad578181015183820152602001610095565b50505050905090810190601f1680156100da5780820380516001836020036101000a031916815260200191505b509250505060405180910390f35b3480156100f457600080fd5b506101006004356102a0565b60408051918252519081900360200190f35b34801561011e57600080fd5b506100736004356102fe565b6040805160208082528183019092526060918291600091829182918591908082016104008038833901905050945060009350600092505b60208310156101ee576008830260020a870291507fff000000000000000000000000000000000000000000000000000000000000008216156101e3578185858151811015156101ac57fe5b9060200101907effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916908160001a9053506001909301925b600190920191610161565b836040519080825280601f01601f19166020018201604052801561021c578160200160208202803883390190505b509050600092505b8383101561029657848381518110151561023a57fe5b90602001015160f860020a900460f860020a02818481518110151561025b57fe5b9060200101907effffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff1916908160001a905350600190920191610224565b9695505050505050565b60008115156102d057507f30000000000000000000000000000000000000000000000000000000000000006102f9565b60008211156102f95761010081049050600a820660300160f860020a0217600a820491506102d0565b919050565b606061031161030c836102a0565b61012a565b929150505600a165627a7a7230582059e7cd89eba2e548bc413b0295f4e8b63781a8c8251e0ca6961fb928a6e0959c0029";

    public static final String FUNC_BYTES32TOSTRING = "bytes32ToString";

    public static final String FUNC_UINTTOBYTES = "uintToBytes";

    public static final String FUNC_UINTTOSTRING = "uintToString";

    @Deprecated
    protected StringUtils(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    protected StringUtils(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, credentials, contractGasProvider);
    }

    @Deprecated
    protected StringUtils(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        super(BINARY, contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    protected StringUtils(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        super(BINARY, contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public RemoteCall<String> bytes32ToString(byte[] x) {
        final Function function = new Function(FUNC_BYTES32TOSTRING, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Bytes32(x)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    public RemoteCall<byte[]> uintToBytes(BigInteger v) {
        final Function function = new Function(FUNC_UINTTOBYTES, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(v)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Bytes32>() {}));
        return executeRemoteCallSingleValueReturn(function, byte[].class);
    }

    public RemoteCall<String> uintToString(BigInteger v) {
        final Function function = new Function(FUNC_UINTTOSTRING, 
                Arrays.<Type>asList(new org.web3j.abi.datatypes.generated.Uint256(v)), 
                Arrays.<TypeReference<?>>asList(new TypeReference<Utf8String>() {}));
        return executeRemoteCallSingleValueReturn(function, String.class);
    }

    @Deprecated
    public static StringUtils load(String contractAddress, Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return new StringUtils(contractAddress, web3j, credentials, gasPrice, gasLimit);
    }

    @Deprecated
    public static StringUtils load(String contractAddress, Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return new StringUtils(contractAddress, web3j, transactionManager, gasPrice, gasLimit);
    }

    public static StringUtils load(String contractAddress, Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return new StringUtils(contractAddress, web3j, credentials, contractGasProvider);
    }

    public static StringUtils load(String contractAddress, Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return new StringUtils(contractAddress, web3j, transactionManager, contractGasProvider);
    }

    public static RemoteCall<StringUtils> deploy(Web3j web3j, Credentials credentials, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(StringUtils.class, web3j, credentials, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<StringUtils> deploy(Web3j web3j, Credentials credentials, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(StringUtils.class, web3j, credentials, gasPrice, gasLimit, BINARY, "");
    }

    public static RemoteCall<StringUtils> deploy(Web3j web3j, TransactionManager transactionManager, ContractGasProvider contractGasProvider) {
        return deployRemoteCall(StringUtils.class, web3j, transactionManager, contractGasProvider, BINARY, "");
    }

    @Deprecated
    public static RemoteCall<StringUtils> deploy(Web3j web3j, TransactionManager transactionManager, BigInteger gasPrice, BigInteger gasLimit) {
        return deployRemoteCall(StringUtils.class, web3j, transactionManager, gasPrice, gasLimit, BINARY, "");
    }
}
